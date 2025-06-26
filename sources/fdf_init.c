/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:13:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 13:24:52 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "fdf.h"

void	fdf_create_vector(t_vars *vars)
{
	size_t		i;
	const float	invx = 2.0f / vars->cols;
	const float	invy = 2.0f / vars->rows;
	const float	invz = 2.0f / (vars->max - vars->min);

	i = 0;
	while (i < vars->length)
	{
		vars->vec[i].x = vars->vtx[i].x * invx - 1.0f;
		vars->vec[i].y = vars->vtx[i].y * invy - 1.0f;
		vars->vec[i].z = (vars->vtx[i].z - vars->min) * invz - 1.0f;
		vars->vec[i].w = vars->vtx[i].color;
		i++;
	}
}

void	init_vars(t_vars *vars)
{
	vars->params.rx = 0.0f;
	vars->params.ry = 0.0f;
	vars->params.rz = 0.0f;
	vars->params.dx = 0.0f;
	vars->params.dy = 0.0f;
	vars->params.dz = 0.0f;
	vars->mlx = NULL;
	vars->vtx = NULL;
	fdf_read("archive/maps/elem2.fdf", " \n", vars);
	fdf_create_vector(vars);
	vars->mlx = mlx_init();
	mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Hello world!");
	vars->img = mlx_int_new_image(vars->mlx, WIDTH, HEIGHT, ZPixmap);
}
