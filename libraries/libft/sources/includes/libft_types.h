/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 15:17:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <stdint.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef union u_type32
{
	uint32_t	ui;
	int32_t		i;
	uint8_t		b[4];
	float		f;
}	t_32;

typedef union u_type64
{
	uint64_t	ul;
	int64_t		l;
	double		d;
	float		f[2];
	uint32_t	ui[2];
	int32_t		i[2];
	uint8_t		b[8];
}	t_64;

typedef struct s_array
{
	union
	{
		void		*v;
		size_t		*w;
		int8_t		*i8;
		uint8_t		*u8;
		int32_t		*i32;
		uint32_t	*u32;
		int64_t		*i64;
		uint64_t	*u64;
		float		*f32;
		double		*f64;
	};
	size_t		length;
}	t_array;

#endif