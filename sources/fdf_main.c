/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 13:18:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "fdf.h"

int	cmlx_loop(t_vars *vars)
{
	fdf_create_vector(vars);
	ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	apply_vertex(vars, vars->vec);
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}

int	main(void)
{
	t_vars vars;

	init_vars(&vars);
	mlx_hook(vars.mlx->win_list, KeyPress, KeyPressMask, cmlx_keydown, &vars);
	mlx_hook(vars.mlx->win_list, KeyRelease, KeyReleaseMask, cmlx_keyup, &vars);
	mlx_hook(vars.mlx->win_list, ButtonPress, ButtonPressMask, cmlx_mousedown, &vars);
	mlx_hook(vars.mlx->win_list, ButtonRelease, ButtonReleaseMask, cmlx_mouseup, &vars);
	mlx_hook(vars.mlx->win_list, Expose, ExposureMask, cmlx_expose, &vars);
	mlx_loop_hook(vars.mlx, cmlx_loop, &vars);
	mlx_loop(vars.mlx);
	cmlx_destroy(&vars);
	return (0);
}
