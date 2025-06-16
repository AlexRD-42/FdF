/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 19:04:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>

// Count elements
size_t	ft_read_size(int fd, const char *charset)
{
	uint8_t	buffer[4096];
	ssize_t	bytes_read;
	size_t	count;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = 0;
	count = ft_count_tokens(buffer, charset, NULL);
	// while (bytes_read > 0)
	// {
		
	// }
}

int	main(void)
{
	int	fd;
	char *str;
	char *str_array[32];
	size_t i = 0;

	fd = open("resources/maps/42.fdf", O_RDONLY);
	ft_read_size(fd, " \n");
}
