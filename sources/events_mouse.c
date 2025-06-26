/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 19:34:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

// 4 ButtonPress
// 12345 = LMB MMB RMB WHEELUP WHEELDOWN
int cmlx_mousedown(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	vars->keys.lmb = (button == 1);
	vars->keys.rmb = (button == 3);
	vars->mouse.x0 = ix;
	vars->mouse.y0 = iy;
	if (button == 4)
		vars->zoom += 0.1f;
	else if (button == 5)
		vars->zoom = ft_max(vars->zoom - 0.1f, 0.1f);
	return (0);
}

// 5 ButtonRelease
int cmlx_mouseup(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	vars->keys.lmb &= (button != 1);
	vars->keys.rmb &= (button != 3);
	vars->mouse.x1 = ix;
	vars->mouse.y1 = iy;
	return (0);
}

// 6 MotionNotify
int cmlx_mousemove(int32_t ix, int32_t iy, t_vars *vars)
{
	if (vars->keys.lmb != 0)
	{
		vars->params.dx = (float) (ix - vars->mouse.x0) / 128.0f;
		vars->params.dy = (float) (iy - vars->mouse.y0) / 128.0f;
		vars->mouse.x0 = ix;
		vars->mouse.y0 = iy;
	}
	else if (vars->keys.rmb != 0)
	{
		vars->params.ry = -(float) (ix - vars->mouse.x0) / 128.0f;
		vars->params.rx = -(float) (iy - vars->mouse.y0) / 128.0f;
		vars->mouse.x0 = ix;
		vars->mouse.y0 = iy;
	}
	return (0);
}
