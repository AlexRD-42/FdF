/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 13:34:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <fdf_utils.h>
#include "fdf.h"

int	cmlx_loop(t_vars *vars)
{
	static const float	vtbl[2] = {0.0f, 0.03125f};

	if (vars->keys.lmb == 0 && vars->keys.rmb == 0)
	{
		vars->params.rx = vtbl[vars->keys.w] - vtbl[vars->keys.s];
		vars->params.ry = vtbl[vars->keys.e] - vtbl[vars->keys.q];
		vars->params.rz = vtbl[vars->keys.d] - vtbl[vars->keys.a];
		vars->params.dx = vtbl[vars->keys.right] - vtbl[vars->keys.left];
		vars->params.dy = vtbl[vars->keys.down] - vtbl[vars->keys.up];
		vars->params.dz = 0.0f;
	}
	else
	{
		vars->params.rx *= 0.5f;
		vars->params.ry *= 0.5f;
		vars->params.rz = 0.0f;
		vars->params.dx *= 0.5f;
		vars->params.dy *= 0.5f;
		vars->params.dz = 0.0f;
	}
	fdf_render_frame(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	// if (fdf_init(&vars, "archive/maps/t2.fdf", " \n"))
	// 	return (1);
	if (fdf_init(&vars, argv[1], " \n"))
		return (1);
	mlx_destroy_window(vars.mlx, vars.mlx->win_list);
	mlx_destroy_image(vars.mlx, vars.img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.vtx);
	return (0);
}
