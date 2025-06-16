/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:22:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/12 09:36:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <math.h>

// typedef union u_pointers
// {
// 	int8_t		*i8;
// 	uint8_t		*u8;
// 	int32_t		*i32;
// 	uint32_t	*u32;
// 	int64_t		*i64;
// 	uint64_t	*u64;
// 	float		*f32;
// 	double		*f64;
// }	t_ptr;

typedef struct s_matrix
{
	float		*data;
	uint32_t	rows;
	uint32_t	cols;
}	t_matrix;

