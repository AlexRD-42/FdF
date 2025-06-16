/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:50:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 18:39:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
 #define FDF_H

// suss
typedef struct s_matrix
{
	float		*data;
	uint32_t	rows;
	uint32_t	cols;
}	t_matrix;

#endif