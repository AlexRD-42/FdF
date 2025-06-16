/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_primes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:58:48 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 15:54:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

size_t	ft_fibonacci(size_t index)
{
	size_t	previous;
	size_t	current;
	size_t	next;

	next = index;
	previous = 0;
	current = 1;
	while (index > 1)
	{
		next = previous + current;
		previous = current;
		current = next;
		index--;
	}
	return (next);
}

uint8_t	ft_isprime(size_t number)
{
	size_t	factor;

	if (number <= 1 || number % 2 == 0 || number % 3 == 0)
		return (number == 2 || number == 3);
	factor = 5;
	while (factor * factor <= number)
	{
		if (number % factor == 0 || number % (factor + 2) == 0)
			return (0);
		factor += 6;
	}
	return (1);
}
