/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:42:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 08:58:27 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#define BUF_META_DATA 100
#define BUF_FIRST_LINE 10002

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	read_meta_data(int fd, int *len, t_map *map)
{
	char	meta_data[BUF_META_DATA];
	int		i;

	i = 0;
	while (read(fd, &meta_data[i], 1) && i < BUF_META_DATA)
	{
		if (meta_data[i] == '\n' || meta_data[i] == '\0')
			break ;
		i++;
	}
	if (meta_data[i] == 0)
		return (0);
	*len = i + 1;
	map->meta_data = malloc(sizeof(char) * (*len));
	if (!map->meta_data)
		return (0);
	i = -1;
	while (++i < *len)
		map->meta_data[i] = meta_data[i];
	map->meta_data[*len] = '\0';
	*len -= 1;
	return (1);
}

int		read_first_line(int fd, int *len, t_map *map)
{
	char	meta_data[BUF_FIRST_LINE];
	int		i;

	i = 0;
	while (read(fd, &meta_data[i], 1) && i < BUF_FIRST_LINE)
	{
		if (meta_data[i] == '\n' || meta_data[i] == '\0')
			break ;
		i++;
	}
	*len = i + 1;
	map->line = malloc(sizeof(char) * (*len));
	if (!map->line)
		return (0);
	i = -1;
	while (++i < *len)
		map->line[i] = meta_data[i];
	map->line[*len] = '\0';
	*len -= 1;
	return (1);
}

int	read_middle_line(int fd, int *len, t_map *map)
{
	char	meta_data[BUF_FIRST_LINE];
	int		i;

	*len = read(fd, &meta_data, map->width + 1);
	if (meta_data[map->width] != '\n' || *len != map->width + 1)
		return (0);
	*len += 1;
	i = -1;
	while (++i < *len)
		map->line[i] = meta_data[i];
	map->line[*len] = '\0';
	*len -= 1;
	return (1);
}

int	read_last_line(int fd)
{
	char	meta_data[BUF_FIRST_LINE];
	int		i;

	i = 0;
	while (read(fd, &meta_data[i], 1) && i < BUF_FIRST_LINE)
	{
		if (meta_data[i] != '\n' || meta_data[i] != '\0')
			return (0);
		i++;
	}
	if (meta_data[i] == '\0' || i == 0)
		return (1);
	return (0);
}

int free_map_line(t_map *map)
{
	if (map->line)
	{
		free(map->line);
		map->line = 0;
		return(0);
	}
	return (1);
}

int free_map_map(t_map *map)
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

int free_map_meta(t_map *map)
{
	if (map->meta_data)
		free(map->meta_data);
	return (0);
}

int	free_map(t_map *map)
{
	if(!map)
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
int	matrix_line(t_map *map, int row)
{
	int i;

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

int	get_map_matrix(t_map *map, int fd)
{
	int	i;
	int len;

	i = 1;
	if (!create_blank_map(map))
		return (0);
	if (!matrix_line(map, 0))
		return (0);
	while (i < map->height - 1)
	{
		if (!read_middle_line(fd, &len, map))
			return (0);
		if (!matrix_line(map, i))
			return (0);
		if (map->line[map->width] != '\n')
			return (0);
		i++;
	}
	if (map->height > 1)
	{
		if (!read_middle_line(fd, &len, map))
			return (0);
		if (!matrix_line(map, i))
			return (0);
		if (!(map->line[map->width] == '\n' || map->line[map->width] == '0'))
			return (0);
	}
	if (!read_last_line(fd))
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
