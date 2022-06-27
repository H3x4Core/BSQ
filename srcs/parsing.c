/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:10 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 18:52:15 by matwinte         ###   ########.fr       */
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
	free(map);
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
	int	len;

	i = 0;
	len = get_next_line(&str[i]);
	i += get_map_height(str, &map->height, len);
	i += get_map_char(str[len - 4], &map->emp);
	i += get_map_char(str[len - 3], &map->obs);
	i += get_map_char(str[len - 2], &map->full);
	i += get_next_line(&str[i]);
	get_map_length(&str[len + 1], &map->width);
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
	int	str_len_chk;
	int	i;
	int	j;

	i = -1;
	str_pos = get_next_line(str);
	if (!create_blank_map(map))
		return (0);
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (str[str_pos + j] == map->emp || str[str_pos + j] == map->obs)
				map->map[i][j] = str[str_pos + j];
			else
				return (free_map(map));
		}
		str_len_chk = str_pos;
		str_pos += get_next_line(&str[str_pos]);
		if ((str_pos - 1) - str_len_chk != map->width)
			return (free_map(map));
	}
	return (1);
}

t_map	*parsing(char *str)
{
	t_map	*map;

	if (!str)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (free_str(str));
	if (!get_map_info(map, str))
		return (free_str(str));
	if (!get_map_matrix(map, str))
		return (free_str(str));
	free_str(str);
	return (map);
}
