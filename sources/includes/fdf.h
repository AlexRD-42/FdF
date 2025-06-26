/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 12:56:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stddef.h>
# include "cmlx.h"

# include "fdf_structs.h"

# define WIDTH 1920
# define HEIGHT 1080
# define AR (float) WIDTH / (float) HEIGHT
# define SCALE 16
# define ZSCALE 0.3f
# define DEFAULT_ZOOM 1.0f

void	fdf_read(const char *str, const char *charset, t_vars *vars);
void	fdf_create_vector(t_vars *vars);
void	fdf_error(t_vars *vars, uint8_t error_code, int32_t fd);
void	draw_lines(t_vars *vars);
void	apply_vertex(t_vars *vars, t_vec4 *v);

void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb);
void	cmlx_destroy(t_vars *vars);

int		cmlx_loop(t_vars *vars);
int 	cmlx_keydown(int keycode, t_vars *vars);
int 	cmlx_keyup(int keycode, t_vars *vars);
int 	cmlx_mousedown(int button, int x, int y, t_vars *vars);
int 	cmlx_mouseup(int button, int x, int y, t_vars *vars);
int 	cmlx_expose(t_vars *vars);

#endif