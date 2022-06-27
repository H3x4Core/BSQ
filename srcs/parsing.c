/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:05:10 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 15:28:39 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_char_is_numeric(char c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int	ft_char_is_printable(char c)
{
	if (c < ' ' || '~' < c)
		return (0);
	return (1);
}

int	get_map_height(char *str, int *nbr)
{
	int	i;

	i = 0;
	*nbr = 0;
	while (ft_char_is_numeric(str[i]))
	{
		*nbr *= 10;
		*nbr += (str[i] - '0');
		i++;
	}
	return (i);
}

int	get_map_char(char c, char *cmap)
{
	if (ft_char_is_printable(c))
		*cmap = c;
	else
		*cmap = 0;
	return (1);
}

int get_map_info(t_map *map, char *str)
{
	int	i;

	i = 0;
	i += get_map_height(str, &map->height);
	i += get_map_char(str[i], &map->emp);
	i += get_map_char(str[i], &map->obs);
	i += get_map_char(str[i], &map->full);
	if (map->height < 1 || map->emp == 0 || map->obs == 0
		|| map->full == 0 || map->emp == map->obs
		|| map->emp == map->full || map->obs == map->full)
		return (0);
	return (1);
}

int get_next_line(char *str)
{
	int i;
	
	i = 0;
	while (str != '\n')
	{
		/* code */
	}
	
}

int get_map_matrix(t_map *map, char *str)
{
	
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
		return (0)
	if (!get_map_matrix(map, str))
		return (0)
	return (map);

}

void	print_map_info(t_map *map)
{
	printf("w: %i\nh: %i\no: %c\ne: %c\nf: %c\n", map->width, map->height, map->obs, map->emp, map->full);
}

int	main(void)
{
	t_map *map;
	char *filename = "map.txt";

	map = parsing(filename);
	print_map_info(map);

	return (0);
}