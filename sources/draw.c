/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 17:57:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>
#include "fdf_utils.h"
#include "fdf.h"

static inline
void	putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
{
	((uint32_t (*)[img->width])img->data)[y][x] = argb;
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

void	draw_neighbours(t_vars *vars, size_t row, size_t col)
{
	t_vtx			p0;
	t_vtx			p1;
	const float		s[2] = {0.5f * WIDTH * vars->params.zoom,
		0.5f * HEIGHT * vars->params.zoom};
	const uintptr_t	offset = row * vars->cols + col;
	const uintptr_t	index[2] = {offset + 1, offset + vars->cols};

	p0.x = vars->vec[offset].x * s[0] + WIDTH * 0.5f;
	p0.y = vars->vec[offset].y * s[1] + HEIGHT * 0.5f;
	p0.color = vars->vtx[offset].color;
	if (col + 1 < vars->cols)
	{
		p1.x = vars->vec[index[0]].x * s[0] + WIDTH * 0.5f;
		p1.y = vars->vec[index[0]].y * s[1] + HEIGHT * 0.5f;
		p1.color = vars->vtx[index[0]].color;
		dline_float(vars->img, p0, p1);
	}
	if (row + 1 < vars->rows)
	{
		p1.x = vars->vec[index[1]].x * s[0] + WIDTH * 0.5f;
		p1.y = vars->vec[index[1]].y * s[1] + HEIGHT * 0.5f;
		p1.color = vars->vtx[index[1]].color;
		dline_float(vars->img, p0, p1);
	}
}
