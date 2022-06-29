/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:37:05 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 15:40:13 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	create_blank_map(t_map *map)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		return (0);
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(char) * map->width);
		if (!map->map[i])
			return (0);
		i++;
	}
	return (1);
}

int	matrix_line(t_map *map, int row)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->line[i] == map->emp || map->line[i] == map->obs)
			map->map[row][i] = map->line[i];
		else
			return (0);
		i++;
	}
	return (1);
}

int	matrix_read_and_line(int fd, int *i, t_map *map)
{
	if (!read_middle_line(fd, map))
		return (0);
	if (!matrix_line(map, *i))
		return (0);
	return (1);
}

int	get_map_matrix(t_map *map, int fd)
{
	int	i;

	i = 1;
	if (!create_blank_map(map))
		return (0);
	if (!matrix_line(map, 0))
		return (0);
	while (i < map->height - 1)
	{
		if (!matrix_read_and_line(fd, &i, map))
			return (0);
		if (map->line[map->width] != '\n')
			return (0);
		i++;
	}
	if (map->height > 1)
	{
		if (!matrix_read_and_line(fd, &i, map))
			return (0);
		if (!(map->line[map->width] == '\n' || map->line[map->width] == '0'))
			return (0);
	}
	if (!read_last_line(fd))
		return (0);
	return (1);
}
