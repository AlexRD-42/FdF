/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_orth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:46:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 15:35:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

static inline
t_mat4	build_affmat(t_params params)
{
	const t_vec3	vcos = {cosf(params.rx), cosf(params.ry), cosf(params.rz)};
	const t_vec3	vsin = {sinf(params.rx), sinf(params.ry), sinf(params.rz)};
	const t_mat4	matrix = {{
		{vcos.z * vcos.y, - vsin.z * vcos.y, vsin.y, params.dx},
		{vcos.z * vsin.y * vsin.x + vsin.z * vcos.x, - vsin.z * vsin.y * vsin.x
		+ vcos.z * vcos.x, - vcos.y * vsin.x, params.dy},
		{-vcos.z * vsin.y * vcos.x + vsin.z * vsin.x, vsin.z * vsin.y * vcos.x
		+ vcos.z * vsin.x, vcos.y * vcos.x, params.dz},
		{0, 0, 0, 1}}};

	return (matrix);
}

void	apply_vertex(t_vars *vars, t_vec4 *v)
{
	const t_mat4	mat = build_affmat(vars->params);
	size_t			i;
	t_vec3			tmp;

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
