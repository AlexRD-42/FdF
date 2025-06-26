/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 17:31:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

// Calculate a gradient that goes from p0 to p1 color (Alpha goes from 00 to FF basically)
// Everything here should be an integer, floats should only be used to determine p0.X -> p1.X by scaling to display
// This function should receive integer points, other function responsability to determine this
static
void	dline_float(t_img *img, t_vtx p0, t_vtx p1)
{
	const uint32_t	length = ft_imax(ft_iabs((p1.x - p0.x)), ft_iabs((p1.y - p0.y)));
	const float		dx = (double) (p1.x - p0.x) / (double) length;
	const float		dy = (double) (p1.y - p0.y) / (double) length;
	uint32_t		i;
	t_vec2			vector;

	i = 0;
	vector.x = p0.x;
	vector.y = p0.y;
	while (i <= length)
	{
		if (vector.x > 0 && vector.y > 0 && vector.x < WIDTH && vector.y < HEIGHT)
			cmlx_putrgb(img, vector.x, vector.y, p0.color);
		vector.x += dx;
		vector.y += dy;
		i++;
	}
}

// Clamping should occur in draw line
// It is acceptable for the image to have pairs that are outside of the drawing region
// But the slope of the line should be preseved when clamping
// If all points are outside of the draw region, no-op
static
void	draw_neighbours(t_vars *vars, size_t row, size_t col)
{
	t_vtx	p0;
	t_vtx	p1;
	t_vec4 	(*vector)[vars->cols] = (t_vec4 (*)[vars->cols])vars->vec;
	t_vtx 	(*vertex)[vars->cols] = (t_vtx (*)[vars->cols])vars->vtx;

	p0.x = (vector[row][col].x + 1.0f) * 0.5f * WIDTH * vars->zoom;
	p0.y = (vector[row][col].y + 1.0f) * 0.5f * HEIGHT * vars->zoom;
	p0.color = vertex[row][col].color;
	if (col + 1 < vars->cols)
	{
		p1.x = (vector[row][col + 1].x + 1.0f) * 0.5f * WIDTH * vars->zoom;
		p1.y = (vector[row][col + 1].y + 1.0f) * 0.5f * HEIGHT * vars->zoom;
		p1.color = vertex[row][col + 1].color;
		dline_float(vars->img, p0, p1);
	}
	if (row + 1 < vars->rows)
	{
		p1.x = (vector[row + 1][col].x + 1.0f) * 0.5f * WIDTH * vars->zoom;
		p1.y = (vector[row + 1][col].y + 1.0f) * 0.5f * HEIGHT * vars->zoom;
		p1.color = vertex[row + 1][col].color;
		dline_float(vars->img, p0, p1);
	}
}

// Could pre-compute neighbour pairs for better cache prediction and eliminate branching
// Total number of pairs = (rows - 1) * cols + (cols - 1) * rows
// = 2 rows*cols - rows - cols
void	draw_lines(t_vars *vars)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < vars->rows)
	{
		col = 0;
		while (col < vars->cols)
		{
			draw_neighbours(vars, row, col);
			col++;
		}
		row++;
	}
}
