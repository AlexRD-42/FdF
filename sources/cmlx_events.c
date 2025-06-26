/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmlx_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 13:31:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "libft_math.h"

// 2 KeyRelease
int cmlx_keydown(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx));
	vars->params.rx += ((keycode == XK_w) - (keycode == XK_s)) * PI/16;
	vars->params.ry += ((keycode == XK_a) - (keycode == XK_d)) * PI/16;
	vars->params.rz += ((keycode == XK_e) - (keycode == XK_q)) * PI/16;
	vars->params.dx += ((keycode == XK_Right) - (keycode == XK_Left)) * PI/16;
	vars->params.dy += ((keycode == XK_Down) - (keycode == XK_Up)) * PI/16;
	vars->params.dz += 0;
	if (keycode == XK_r)
		fdf_create_vector(vars);
}

// 3 KeyPress
int cmlx_keyup(int keycode, t_vars *vars)
{

}

// 4 ButtonPress
// 12345 = LMB MMB RMB WHEELUP WHEELDOWN
int cmlx_mousedown(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	if (button == 4)
		vars->zoom += 0.1f;
	else if (button == 5)
		vars->zoom = ft_max(vars->zoom - 0.1f, 0.1f);
}

// 5 ButtonRelease
int cmlx_mouseup(int button, int x, int y, t_vars *vars)
{

}

// 12 Expose (why does it run twice)
int cmlx_expose(t_vars *vars)
{

}
