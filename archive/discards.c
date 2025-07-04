/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discards.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:51:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/04 12:30:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

// Calculate a gradient that goes from p0 to p1 color (Alpha goes from 00 to FF basically)
// Everything here should be an integer, floats should only be used to determine p0.X -> p1.X by scaling to display
// This function should receive integer points, other function responsability to determine this

// Could pre-compute neighbour pairs for better cache prediction and eliminate branching
// Total number of pairs = (rows - 1) * cols + (cols - 1) * rows
// = 2 rows*cols - rows - cols
                        ((uint32_t (*)[img->width])img->data) [(uint32_t)vector.y][(uint32_t)vector.x] = p0.color;


inline
void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
{
	uint32_t		*dst;
	const uint32_t	alpha = src >> 24;
	uint32_t		rb_dst; 
	uint32_t		ga_dst;

	dst = (uint32_t *) (img->data + y * img->width + x);
	rb_dst = *dst & 0x00FF00FF;
	ga_dst = (*dst >> 8) & 0x00FF00FF;
	rb_dst += (((src & 0x00FF00FF) - rb_dst) * alpha) >> 8;
	ga_dst += ((((src >> 8) & 0x00FF00FF) - ga_dst) * alpha) >> 8;
	*dst = (rb_dst & 0x00FF00FF) | ((ga_dst & 0x00FF00FF) << 8);
}

static inline
t_mat4	build_mvpmatrix(t_params p, t_frustrum f)
{
	const t_vec3	vc = {cosf(p.rx), cosf(p.ry), cosf(p.rz)};
	const t_vec3	vs = {sinf(p.rx), sinf(p.ry), sinf(p.rz)};
	const t_vec4	v1 = {1.0f / tanf(f.fov * 0.5f), -vc.z * vs.y * vc.x + vs.z
		* vs.x, vs.z * vs.y * vc.x + vc.z * vs.x, vc.y * vc.x};
	const t_vec4	v2 = {v1.x / f.ar, v1.x, (f.far + f.near)
		/ (f.near - f.far), 2.0f * f.far * f.near / (f.near - f.far)};

	return ((t_mat4){{
		{v2.x * vc.z * vc.y, v2.x * -vs.z * vc.y, v2.x * vs.y, v2.x * p.dx},
		{v2.y * (vc.z * vs.y * vs.x + vs.z * vc.x), v2.y * (-vs.z * vs.y * vs.x + vc.z * vc.x), v2.y * (-vc.y * vs.x), v2.y * p.dy},
		{v2.z * v1.y, v2.z * v1.z, v2.z * v1.w, v2.z * p.dz + v2.w},
		{-v1.y, -v1.z, -v1.w, -p.dz}}});
}

static
void	dline_float(t_img *img, t_vtx p0, t_vtx p1)
{
	const uint32_t	length = ft_iabsmax((p1.x - p0.x), (p1.y - p0.y));
	const float		dx = (double)(p1.x - p0.x) / (double)length;
	const float		dy = (double)(p1.y - p0.y) / (double)length;
	uint32_t		i;
	t_vec2			vec;

	i = 0;
	vec.x = p0.x;
	vec.y = p0.y;
	while (i <= length)
	{
		if (vec.x >= 0.0f && vec.y >= 0.0f && vec.x < WIDTH && vec.y < HEIGHT)
			putrgb(img, vec.x, vec.y, p0.color);
		vec.x += dx;
		vec.y += dy;
		i++;
	}
}

static
void	draw_line(t_img *img, t_vtx p0, t_vtx p1)
{
	const t_vtx2	delta = {ft_iabs(p1.x - p0.x), ft_iabs(p1.y - p0.y)};
	const int32_t	sx = (p0.x < p1.x) - (p0.x >= p1.x);
	const int32_t	sy = (p0.y < p1.y) - (p0.y >= p1.y);
	int32_t			err;
	int32_t			e2;

	err = delta.x - delta.y;
	while (1)
	{
		if (p0.x >= 0 && p0.y >= 0 && p0.x < WIDTH && p0.y < HEIGHT)
			putrgb(img, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e2 = err * 2;
		if (e2 > -delta.y)
		{
			err -= delta.y;
			p0.x += sx;
		}
		if (e2 < delta.x)
		{
			err += delta.x;
			p0.y += sy;
		}
	}
}

// static
// void	dline_bresenham(t_img *img, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
// {
// 	const int32_t	dx = (x1 - x0);
// 	const int32_t	dy = (y1 - y0);
// 	int32_t			offset;

// 	offset = 2 * dy - dx;
// 	while (x0 < x1 || y0 < y1)
// 	{
// 		cmlx_putpixel(img, x0, y0, 0x00FFFFFF);
// 		y0 += (offset > 0);
// 		x0++;
// 		offset += (dy << 1) - (dx << (offset > 0));
// 	}
// }


void	fill_screen(t_img *img, uint32_t argb)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			cmlx_putpixel(img, i, j, argb);
			j++;
		}
		i++;
	}
}
static inline
float	fdf_lerp(const int32_t min, const int32_t max, const int32_t val)
{
	// return ((float)(((double)((min + val) << 1) / (double)(max + min)) - 1.0));
	return (((val - min) * 2.0f) / (max - min) - 1.0f);
}

static inline
float	ft_clamp(const float upper, const float lower, float value)
{
	if (value > upper)
		return (upper);
	else if (value < lower)
		return (lower);
	return (value);
}

static inline
float	absmaxvec(t_vec3 vec)
{
	return (ft_max(ft_abs(vec.z), ft_max(ft_abs(vec.x), ft_abs(vec.y))));
}

static
void	normalize(t_vec3 *vec, size_t length)
{
	size_t	i;
	float	max = 0.0f;

	i = 0;
	while (i < length)
		max = ft_max(ft_abs(max), absmaxvec(vec[i++]));
	max = 1.0f / max;
	i = 0;
	while (i < length)
	{
		vec[i].x *= max;
		vec[i].y *= max;
		vec[i].z *= max;
		i++;
	}
}

__always_inline
void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
{
	uint32_t	*dst;
	uint64_t	argb_dst;
	uint64_t	argb_src;
	uint64_t	alpha;
	uint64_t	reg64;

	alpha = (src >> 24);
	dst = (uint32_t *) (img->data + y * img->width + x);
	argb_dst = (((uint64_t) *dst) & 0xFF00FF00ULL) << 32;
	argb_dst |= ((uint64_t) *dst) & 0x00FF00FFULL;
	argb_src = (((uint64_t) src) & 0xFF00FF00ULL) << 32;
	argb_src |= ((uint64_t) src) & 0x00FF00FFULL;
	reg64 = (argb_dst + (argb_src - argb_dst) * alpha) >> 8;
	reg64 &= 0x00FF00FF00FF00FFULL;
	reg64 = ((reg64 >> 32) | reg64) & 0xFFFFFFFFULL;
	*dst = (uint32_t) reg64;
}

typedef struct s_frustrum
{
	float	near;	// Near z plane camera
	float	far;	// Far z plane camera
	float	fov;	// Field of view
	float	ar;		// Aspect Ratio
}	t_frustrum;


// dp how many pixels changed
// void	motion_smoothing(uint8_t dp)
// {
// 	static	size_t	total = 0;

// 	total = total << dp + total >> 1;
// }

// void	motion_smoothing(float dxyz)
// {
// 	static float	total = 1;

// 	total *= (dxyz + 0.5);
// }

