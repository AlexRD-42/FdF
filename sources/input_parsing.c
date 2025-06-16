/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:07:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 12:04:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"

#define FILEDIR "resources/maps/"

static
void	remove_nl(char *str)
{
	if (str == NULL || *str == 0)
		return ;
	while (*str != 0)
		str++;
	if (*(str - 1) == '\n')
		*(str - 1) = 0;
}

// int	main(void)
// {
// 	int	fd;
// 	char *str;
// 	char *str_array[32];
// 	size_t i = 0;

// 	fd = open(FILEDIR "42.fdf", O_RDONLY);
// 	str = (char*) &fd;
// 	while (str != NULL)
// 	{
// 		str = get_next_line(fd);
// 		remove_nl(str);
// 		str_array[i++] = str;
// 	}
// }
