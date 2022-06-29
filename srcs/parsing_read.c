/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:21 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 15:36:52 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	read_first_line(int fd, int *len, t_map *map)
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

int	read_middle_line(int fd, t_map *map)
{
	char	meta_data[BUF_FIRST_LINE];
	int		i;
	int		len;

	len = read(fd, &meta_data, map->width + 1);
	if (meta_data[map->width] != '\n' || len != map->width + 1)
		return (0);
	len += 1;
	i = -1;
	while (++i < len)
		map->line[i] = meta_data[i];
	map->line[len] = '\0';
	len -= 1;
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
