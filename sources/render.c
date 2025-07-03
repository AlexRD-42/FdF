/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:56:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 18:10:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>
#include "fdf_utils.h"
#include "fdf.h"

static
void	apply_transform(t_vars *vars, t_vec4 *v, t_params params)
{
	size_t			i;
	t_vec3			tmp;
	const t_vec3	vcos = {cosf(params.rx), cosf(params.ry), cosf(params.rz)};
	const t_vec3	vsin = {sinf(params.rx), sinf(params.ry), sinf(params.rz)};
	const t_mat4	mat = {{
	{vcos.z * vcos.y, -vsin.z * vcos.y, vsin.y, params.dx},
	{vcos.z * vsin.y * vsin.x + vsin.z * vcos.x, -vsin.z * vsin.y * vsin.x
		+ vcos.z * vcos.x, -vcos.y * vsin.x, params.dy},
	{-vcos.z * vsin.y * vcos.x + vsin.z * vsin.x, vsin.z * vsin.y * vcos.x
		+ vcos.z * vsin.x, vcos.y * vcos.x, params.dz},
	{0, 0, 0, 1}}};

	i = 0;
	while (i < vars->length)
	{
		tmp.x = mat.a1 * v[i].x + mat.a2 * v[i].y + mat.a3 * v[i].z + mat.a4;
		tmp.y = mat.b1 * v[i].x + mat.b2 * v[i].y + mat.b3 * v[i].z + mat.b4;
		tmp.z = mat.c1 * v[i].x + mat.c2 * v[i].y + mat.c3 * v[i].z + mat.c4;
		v[i].x = tmp.x;
		v[i].y = tmp.y;
		v[i].z = tmp.z;
		i++;
	}
}

static
void	draw_cols(t_vars *vars, size_t row, uint8_t mode)
{
	size_t	col;

	if (mode == 0)
	{
		col = 0;
		while (col < vars->cols)
		{
			draw_neighbours(vars, row, col);
			col++;
		}
	}
	else
	{
		col = vars->cols;
		while (col > 0)
		{
			col--;
			draw_neighbours(vars, row, col);
		}
	}
}

static
void	draw_rows(t_vars *vars, uint8_t mode1, uint8_t mode2)
{
	size_t	row;

	if (mode1 == 0)
	{
		row = 0;
		while (row < vars->rows)
		{
			draw_cols(vars, row, mode2);
			row++;
		}
	}
	else
	{
		row = vars->rows;
		while (row > 0)
		{
			row--;
			draw_cols(vars, row, mode2);
		}
	}
}

void	update_rstate(t_vars *vars)
{
	vars->rot.x += vars->params.rx;
	vars->rot.y += vars->params.ry;
	vars->rot.z += vars->params.rz;
	if (vars->rot.x > PI || vars->rot.x < PI)
		vars->rot.x = 0.0f;
	if (vars->rot.y > PI || vars->rot.y < PI)
		vars->rot.y = 0.0f;
	if (vars->rot.z > PI || vars->rot.z < PI)
		vars->rot.z = 0.0f;
}

void	fdf_render_frame(t_vars *vars)
{
	update_rstate(vars);
	ft_bzero(vars->img->data, HEIGHT * WIDTH * sizeof(int32_t));
	apply_transform(vars, vars->vec, vars->params);
	draw_rows(vars, 1, 0);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}
