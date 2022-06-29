/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:40:42 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 15:46:23 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_map_line(t_map *map)
{
	if (map->line)
	{
		free(map->line);
		map->line = 0;
		return (0);
	}
	return (1);
}

int	free_map_map(t_map *map)
{
	int	i;

	if (map->map)
	{
		while (i < map->height)
		{
			free(map->map[i]);
			map->map[i] = 0;
			i++;
		}
		free(map->map);
		map->map = 0;
	}
	return (0);
}

int	free_map_meta(t_map *map)
{
	if (map->meta_data)
		free(map->meta_data);
	return (0);
}

int	free_map(t_map *map)
{
	if (!map)
		return (0);
	free_map_line(map);
	free_map_map(map);
	free_map_meta(map);
	if (map)
	{
		free(map);
		map = 0;
	}
	return (0);
}
