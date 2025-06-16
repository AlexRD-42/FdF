/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 12:25:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "mlx_int.h"

#define WIDTH 640
#define HEIGHT 480

// uint32_t (*image_array)[img->width] = (uint32_t (*)[img->width])img->data;

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);

static inline
void	put_pixel(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
{
	((uint32_t (*)[img->width])img->data)[y][x] = argb;
}

void	ft_mlx_destroy(t_xvar *mlx, t_img *img)
{
	mlx_destroy_window(mlx, mlx->win_list);
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	free(mlx);
}

static
ssize_t	ft_read(char *buffer)
{
	ssize_t	bytes_read;

	int fd = open("resources/maps/42.fdf", O_RDONLY);
	bytes_read = read(fd, buffer, 4096);
	close(fd);
	return (bytes_read);
}

static
void	draw_image(t_img *img, char *buffer, size_t bytes_read)
{
	size_t	i;
	size_t	j;
	size_t	k = 0;

	i = 0;
	j = 0;
	while (k < bytes_read)
	{
		if (buffer[k] == '\n')
		{
			i = 0;
			j++;
		}
		else
		{
			put_pixel(img, i, j, (buffer[k] == '1' && buffer[k + 1] == '0') * 0x00FFFFFF);
			k += buffer[k] == '1' && buffer[k + 1] == '0';
			i++;
		}
		k++;
	}
}

int	main(void)
{
	t_xvar	*mlx;
	t_img	*img;
	ssize_t	bytes_read;
	static char	buffer[4096];

	mlx = mlx_init();
	mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img = mlx_int_new_image(mlx, WIDTH, HEIGHT, ZPixmap);
	bytes_read = ft_read(buffer);
	draw_image(img, buffer, (size_t) bytes_read);
	// draw_grid(img);
	mlx_put_image_to_window(mlx, mlx->win_list, img, 0, 0);
	ft_mlx_destroy(mlx, img);
}
