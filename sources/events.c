/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 17:09:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "fdf.h"
#include "fdf_utils.h"

// Keymap
// 2 KeyRelease
int	cmlx_keydown(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx));
	if (keycode == XK_r)
		fdf_create_vector(vars);
	if (keycode == XK_1)
		fdf_preset1(vars);
	if (keycode == XK_2)
		fdf_preset2(vars);
	if (keycode == XK_3)
		fdf_preset3(vars);
	if (keycode == XK_4)
		fdf_preset4(vars);
	vars->keys.w = (keycode == XK_w);
	vars->keys.a = (keycode == XK_a);
	vars->keys.s = (keycode == XK_s);
	vars->keys.d = (keycode == XK_d);
	vars->keys.q = (keycode == XK_q);
	vars->keys.e = (keycode == XK_e);
	vars->keys.up = (keycode == XK_Up);
	vars->keys.down = (keycode == XK_Down);
	vars->keys.left = (keycode == XK_Left);
	vars->keys.right = (keycode == XK_Right);
	return (0);
}

// 3 KeyPress
int	cmlx_keyup(int keycode, t_vars *vars)
{
	vars->keys.w &= (keycode != XK_w);
	vars->keys.a &= (keycode != XK_a);
	vars->keys.s &= (keycode != XK_s);
	vars->keys.d &= (keycode != XK_d);
	vars->keys.up &= (keycode != XK_Up);
	vars->keys.down &= (keycode != XK_Down);
	vars->keys.left &= (keycode != XK_Left);
	vars->keys.right &= (keycode != XK_Right);
	vars->keys.q &= (keycode != XK_q);
	vars->keys.e &= (keycode != XK_e);
	return (0);
}

// 4 ButtonPress
// 12345 = LMB MMB RMB WHEELUP WHEELDOWN
int	cmlx_mousedown(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	vars->keys.lmb = (button == 1);
	vars->keys.rmb = (button == 3);
	vars->mouse.x = ix;
	vars->mouse.y = iy;
	if (button == 4)
		vars->params.zoom += 0.1f;
	else if (button == 5)
		vars->params.zoom = ft_max(vars->params.zoom - 0.1f, 0.1f);
	return (0);
}

// 5 ButtonRelease
int	cmlx_mouseup(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	vars->keys.lmb &= (button != 1);
	vars->keys.rmb &= (button != 3);
	vars->mouse.x = ix;
	vars->mouse.y = iy;
	return (0);
}

// 6 MotionNotify
int	cmlx_mousemove(int32_t ix, int32_t iy, t_vars *vars)
{
	if (vars->keys.lmb != 0)
	{
		vars->params.dx = (float)(ix - vars->mouse.x) / 128.0f;
		vars->params.dy = (float)(iy - vars->mouse.y) / 128.0f;
	}
	else if (vars->keys.rmb != 0)
	{
		vars->params.ry = -(float)(ix - vars->mouse.x) / 128.0f;
		vars->params.rx = -(float)(iy - vars->mouse.y) / 128.0f;
	}
	vars->mouse.x = ix;
	vars->mouse.y = iy;
	return (0);
}
