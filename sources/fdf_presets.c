/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_presets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:48:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 17:24:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>
#include "fdf.h"

void	fdf_preset1(t_vars *vars)
{
	fdf_create_vector(vars);
	vars->params.rx = PI / 6;
	vars->params.ry = 0.0f;
	vars->params.rz = PI / 4;
	fdf_render_frame(vars);
}

void	fdf_preset2(t_vars *vars)
{
	fdf_create_vector(vars);
	vars->params.rx = 0.0f;
	vars->params.ry = PI / 4;
	vars->params.rz = 0.0f;
	fdf_render_frame(vars);
}

void	fdf_preset3(t_vars *vars)
{
	fdf_create_vector(vars);
	vars->params.rx = PI / 6;
	vars->params.ry = PI / 6;
	vars->params.rz = 0.0f;
	fdf_render_frame(vars);
}

void	fdf_preset4(t_vars *vars)
{
	fdf_create_vector(vars);
	vars->params.rx = PI / 6;
	vars->params.ry = 0.0f;
	vars->params.rz = PI / 6;
	fdf_render_frame(vars);
}
