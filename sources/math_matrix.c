/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:30:05 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 18:40:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"

void	init_matrix()
{
	
}

void	ft_matmult(const t_matrix *ma, const t_matrix *mb, t_matrix *mc)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	k;
	float		sum;

	i = 0;
	while (i < mc->rows)
	{
		j = 0;
		while (j < mc->cols)
		{
			sum = 0.0f;
			k = 0;
			while (k < ma->cols)
			{
				sum += ma->data[i * ma->cols + k] * mb->data[k * mb->cols + j];
				k++;
			}
			mc->data[i * mc->cols + j] = sum;
			j++;
		}
		i++;
	}
}
