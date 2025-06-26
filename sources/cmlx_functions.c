/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmlx_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 16:08:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include <math.h>
#include "fdf.h"

// Check if this is multiplication
__always_inline
void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
{
	((uint32_t (*)[img->width])img->data)[y][x] = argb;
}

__always_inline
void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
{
	uint32_t		*dst;
	const uint32_t	alpha = src >> 24;
	uint32_t		rb_dst; 
	uint32_t		ga_dst;

	dst = (uint32_t *) (img->data + y * img->width + x);
	rb_dst = *dst & 0x00FF00FF;
	ga_dst = (*dst >> 8) & 0x00FF00FF;
	rb_dst += (((src & 0x00FF00FF) - rb_dst) * alpha) >> 8;
	ga_dst += ((((src >> 8) & 0x00FF00FF) - ga_dst) * alpha) >> 8;
	*dst = (rb_dst & 0x00FF00FF) | ((ga_dst & 0x00FF00FF) << 8);
}

void	cmlx_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx->win_list);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->vtx);
	vars->vec = NULL;
	vars->mlx = NULL;
	vars->vtx = NULL;
	vars->img = NULL;
}
