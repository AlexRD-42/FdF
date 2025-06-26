/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:11:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/26 13:21:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

// Remember to free and close fds
// Maybe an Enum would be better
// static const char *error[] = {
// 	"Error: Number of columns differ",
// 	"Error: Failed to allocate memory",
// 	"Error: Read values do not match",};

void	fdf_error(t_vars *vars, uint8_t error_code, int32_t fd)
{
	
}

static
t_vtx	fdf_atoi(const uint8_t *ustr, size_t index)
{
	t_vtx					vtx;
	int32_t					sign;
	static const uint8_t	lut[256] = {
	['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
	['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
	['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,
	['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

	sign = (*ustr == '-') - (*ustr != '-');
	ustr += (*ustr == '-') || (*ustr == '+');
	vtx.x = (int32_t) index;
	vtx.z = 0;
	vtx.color = 0;
	while (lut[*ustr] || *ustr == '0')
		vtx.z = vtx.z * 10 - lut[*ustr++];
	vtx.z *= sign;
	if (*ustr++ == ',')
	{
		ustr += (ustr[0] == '0' && (ustr[1] == 'x' || ustr[1] == 'X')) << 1;
		while (lut[*ustr] || *ustr == '0')
			vtx.color = (vtx.color << 4) + lut[*ustr++];
	}
	return (vtx);
}

static
t_vtx	*fdf_split(const char *str, const char *charset, size_t *count)
{
	t_vtx			*array;
	size_t			length;
	uint8_t			lut[256];
	const uint8_t	*ustr = (const uint8_t *) str;
	const size_t	tokens = ft_count_tokens(str, ft_setlut256(lut, charset), NULL);

	array = malloc(tokens * (sizeof(t_vtx) + sizeof(t_vec4)));
	if (array == NULL)
		return (NULL);
	*count = 0;
	while (*ustr != 0)
	{
		while (lut[*ustr] == 1)
			ustr++;
		length = 0;
		while (lut[ustr[length]] == 0)
			length++;
		if (length == 0)
			break ;
		array[*count] = fdf_atoi(ustr, *count);
		(*count)++;
		ustr += length;
	}
	*count *= (*count == tokens);
	return (array);
}

static
void	fdf_read_init(const char *str, const char c, t_vars *vars)
{
	size_t			i;
	int32_t			y_index;

	vars->rows = 0;
	while (*str != 0)
		vars->rows += (*str++ == c);
	if (vars->rows == 0 || vars->length % vars->rows != 0)
		return (fdf_error(vars, 3, -1)); // Error Handling
	vars->cols = vars->length / vars->rows;
	vars->min = INT32_MAX;
	vars->max = INT32_MIN;
	vars->zoom = DEFAULT_ZOOM;
	i = 0;
	y_index = 0;
	while (i < vars->length)
	{
		if (vars->vtx[i].z > vars->max)	// This is dumb
			vars->max = vars->vtx[i].z;
		if (vars->vtx[i].z < vars->min)	// This is dumb
			vars->min = vars->vtx[i].z;
		vars->vtx[i].x = (vars->vtx[i].x % vars->cols);
		y_index += (vars->vtx[i].x == 0) && (i != 0);
		vars->vtx[i].y = y_index;
		i++;
	}
}

void	fdf_read(const char *filename, const char *charset, t_vars *vars)
{
	char			*buffer;
	size_t			bytes_read;
	const size_t	total_memory = (size_t) ft_read_size(filename);
	const int32_t	fd = open(filename, O_RDONLY);

	if ((ssize_t) total_memory <= 0 || fd < 0)
		return (fdf_error(vars, 0, fd)); // Error Handling
	buffer = malloc(total_memory + 1);
	if (buffer == NULL)
		return (fdf_error(vars, 1, fd)); // Error Handling
	bytes_read = (size_t) read(fd, buffer, total_memory);
	if ((ssize_t) bytes_read <= 0 || bytes_read != total_memory)
		return (fdf_error(vars, 0, fd)); // Error Handling
	buffer[bytes_read] = 0;
	vars->vtx = fdf_split(buffer, charset, &(vars->length));
	if (vars->vtx == NULL || vars->length == 0)
		return (fdf_error(vars, 1, fd));
	vars->vec = (t_vec4 *) (vars->vtx + vars->length);
	fdf_read_init(buffer, '\n', vars);
	free(buffer);
	close(fd);
}