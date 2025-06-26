/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:14:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 18:18:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include <stdint.h>
# include <stddef.h>
# include "cmlx.h"
# include "fdf_math.h"

typedef struct s_params
{
	float	dx;		// (Top-view) Moves right and left
	float	dy;		// (Top-view) Moves up and down
	float	dz;		// (Top-view) Moves towards the camera
	float	rx;		// Roll
	float	ry;		// Pitch
	float	rz;		// Yaw
}	t_params;

typedef struct s_frustrum
{
	float	near;	// Near z plane camera
	float	far;	// Far z plane camera
	float	fov;	// Field of view
	float	ar;		// Aspect Ratio
}	t_frustrum;

typedef struct s_keys
{
	uint8_t	w;
	uint8_t	a;
	uint8_t	s;
	uint8_t	d;
	uint8_t	q;
	uint8_t	e;
	uint8_t	up;
	uint8_t	down;
	uint8_t	left;
	uint8_t	right;
	uint8_t	rmb;
	uint8_t	lmb;
}	t_keys;

typedef struct s_mouse
{
	int32_t	x0;
	int32_t	y0;
	int32_t	x1;
	int32_t	y1;
}	t_mouse;

typedef struct s_vars
{
	t_xvar		*mlx;
	t_img		*img;
	t_vtx		*vtx;
	t_vec4		*vec;
	t_params	params;
	float		zoom;
	size_t		length;
	int32_t		max;
	int32_t		min;
	uint32_t	rows;
	uint32_t	cols;
	t_keys		keys;
	t_mouse		mouse;
}	t_vars;

#endif