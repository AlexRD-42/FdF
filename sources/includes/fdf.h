/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/03 13:54:09 by adeimlin         ###   ########.fr       */
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

uint8_t	fdf_read(t_vars *vars, const char *filename, const char *charset);
uint8_t	fdf_init(t_vars *vars, const char *filename, const char *charset);
void	fdf_create_vector(t_vars *vars);
void	fdf_render_frame(t_vars *vars);
void	fdf_preset1(t_vars *vars);

int		cmlx_loop(t_vars *vars);
int		cmlx_keydown(int keycode, t_vars *vars);
int		cmlx_keyup(int keycode, t_vars *vars);
int		cmlx_mousedown(int button, int32_t ix, int32_t iy, t_vars *vars);
int		cmlx_mouseup(int button, int32_t ix, int32_t iy, t_vars *vars);
int		cmlx_mousemove(int32_t ix, int32_t iy, t_vars *vars);

#endif