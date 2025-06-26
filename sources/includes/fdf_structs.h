/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:14:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 12:52:21 by adeimlin         ###   ########.fr       */
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

typedef struct s_event_status
{
	uint8_t	alt_pressed;
}	t_evstatus;

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
	t_evstatus	evstatus;
}	t_vars;

#endif