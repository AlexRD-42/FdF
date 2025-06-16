/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:09:13 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 17:02:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
// https://prng.di.unimi.it/xoshiro256plus.c

// Removed seed +=, possibly bad
uint64_t	ft_splitmix64(uint64_t seed)
{
	uint64_t	result;

	result = (seed + 0x9E3779B97f4A7C15);
	result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
	result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
	return (result ^ (result >> 31));
}

// void	ft_rngseed(uint64_t seed)
// {
// 	state[0] = ft_splitmix64(seed);
//     state[1] = ft_splitmix64(state[0]);
//     state[2] = ft_splitmix64(state[1]);
//     state[3] = ft_splitmix64(state[2]);
// }

uint64_t	ft_rand(void)
{
	static uint64_t	state[4] = {9223372036854775783, 6364136223846793005,
		18014398509481951, 1181783497276652981};
	const uint64_t	result = {state[0] + state[3]};
	const uint64_t	t = state[1] << 17;

	state[2] ^= state[0];
	state[3] ^= state[1];
	state[1] ^= state[2];
	state[0] ^= state[3];
	state[2] ^= t;
	state[3] = (state[3] << 45) | (state[3] >> 19);
	return (result);
}
