/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 19:33:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"
#include "fdf.h"

int	render_frame(t_vars *vars)
{
	const float		vtbl[2] = {0.0f, 0.03125f};

	if (vars->keys.lmb == 0 && vars->keys.rmb == 0)
	{
		vars->params.rx = vtbl[vars->keys.w] - vtbl[vars->keys.s];
		vars->params.ry = vtbl[vars->keys.e] - vtbl[vars->keys.q];
		vars->params.rz = vtbl[vars->keys.d] - vtbl[vars->keys.a];
		vars->params.dx = vtbl[vars->keys.right] - vtbl[vars->keys.left];
		vars->params.dy = vtbl[vars->keys.down] - vtbl[vars->keys.up];
	}
	ft_bzero(vars->img->data, HEIGHT * WIDTH * sizeof(int32_t));
	apply_vertex(vars, vars->vec);
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars vars;

	if (fdf_init(&vars, "archive/maps/t1.fdf", " \n"))
		return (1);
	mlx_loop(vars.mlx);
	cmlx_destroy(&vars);
	return (0);
}
