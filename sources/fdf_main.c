/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 16:15:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"
#include "fdf.h"

int	cmlx_loop(t_vars *vars)
{
	fdf_create_vector(vars);
	ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	apply_vertex(vars, vars->vec);
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars vars;

	if (fdf_init(&vars, "archive/maps/mars.fdf", " \n"))
		return (1);
	mlx_loop(vars.mlx);
	cmlx_destroy(&vars);
	return (0);
}
