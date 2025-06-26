/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 17:58:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "libft_math.h"

// Keymap
// 2 KeyRelease
int cmlx_keydown(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx));
	if (keycode == XK_r)
		fdf_create_vector(vars);
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
int cmlx_keyup(int keycode, t_vars *vars)
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
