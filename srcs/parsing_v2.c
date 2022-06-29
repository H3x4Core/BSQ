/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:42:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 15:40:39 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	get_meta_data(t_map *map, int len)
{
	get_map_height(map->meta_data, &map->height, len);
	get_map_char(map->meta_data[len - 3], &map->emp);
	get_map_char(map->meta_data[len - 2], &map->obs);
	get_map_char(map->meta_data[len - 1], &map->full);
}

int	check_map_meta_data(t_map *map)
{
	if (map->height < 1 || map->emp == 0
		|| map->obs == 0 || map->full == 0
		|| map->emp == map->obs || map->emp == map->full
		|| map->obs == map->full)
		return (0);
	return (1);
}

int	get_map_info(t_map *map, int fd)
{
	int		len;

	len = 0;
	read_meta_data(fd, &len, map);
	if (!map->meta_data)
		return (0);
	if (map->meta_data[len] == '\0' || len < 4)
		return (0);
	get_meta_data(map, len);
	if (!check_map_meta_data(map))
		return (0);
	read_first_line(fd, &len, map);
	map->width = len;
	if (!map->line)
		return (0);
	if (map->width < 1)
		return (0);
	return (1);
}

t_map	*parsing(int fd)
{
	t_map	*map;

	map = 0;
	if (fd < 0)
		return (error_map(map));
	map = malloc(sizeof(t_map));
	if (!map)
		return (error_map(map));
	if (!get_map_info(map, fd))
		return (error_map(map));
	if (!get_map_matrix(map, fd))
		return (error_map(map));
	return (map);
}

/*
int main(void)
{
	int fd;
	char *filename = "../issue_map/parsing/unknown/test_vert2.txt";
	t_map *map;

	fd = open_file(filename);
	map = parsing(fd);
	close(fd);
	if (!map)
		return (0);
	printf("%p\n", map);
	debug_print_map_info(map);
	debug_print_map(map);
	free_map(map);
}
*/
