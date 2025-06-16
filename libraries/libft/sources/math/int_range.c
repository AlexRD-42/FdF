/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:59:40 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 19:07:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

size_t	i32_min_index(int32_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

size_t	i32_max_index(int32_t *array, size_t length)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[max])
			max = i;
		i++;
	}
	return (max);
}

size_t	i64_min_index(int64_t *array, size_t length)
{
	size_t	i;
	size_t	min;

	min = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

size_t	i64_max_index(int64_t *array, size_t length)
{
	size_t	i;
	size_t	max;

	max = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[max])
			max = i;
		i++;
	}
	return (max);
}
