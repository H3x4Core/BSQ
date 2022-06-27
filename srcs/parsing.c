/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:10 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 17:04:50 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->map)
		return (0);
	while (i < map->height)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
	return (0);
}

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
			return (free_map(map));
		i++;
	}
	return (1);
}

int	get_map_info(t_map *map, char *str)
{
	int	i;

	i = 0;
	i += get_map_height(str, &map->height);
	i += get_map_char(str[i], &map->emp);
	i += get_map_char(str[i], &map->obs);
	i += get_map_char(str[i], &map->full);
	i += get_next_line(&str[i]);
	get_map_length(&str[i], &map->width);
	if (map->height < 1 || map->width < 1
		|| map->emp == 0 || map->obs == 0
		|| map->full == 0 || map->emp == map->obs
		|| map->emp == map->full || map->obs == map->full)
		return (0);
	return (1);
}

int	get_map_matrix(t_map *map, char *str)
{
	int	str_pos;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str_pos = get_next_line(str);
	if (!create_blank_map(map))
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (str[str_pos + j] == map->emp || str[str_pos + j] == map->obs)
				map->map[i][j] = str[str_pos + j];
			else
				return (free_map(map));
			j++;
		}
		str_pos += get_next_line(&str[str_pos]);
		i++;
	}
	return (1);
}

t_map	*parsing(char *filename)
{
	t_map	*map;
	char	*str;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	str = read_file(filename);
	if (!get_map_info(map, str))
		return (0);
	if (!get_map_matrix(map, str))
		return (0);
	return (map);
}
