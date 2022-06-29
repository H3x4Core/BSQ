/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:09 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/29 08:56:35 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_square_size(t_map *map, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j <= i && row + j < map->height)
		{
			if (map->map[row + i][col + j] == map->obs)
				return (i);
			j++;
		}
		j = 0;
		while (j <= i && col + j < map->width)
		{
			if (map->map[row + j][col + i] == map->obs)
				return (i);
			j++;
		}
		i++;
	}
	return (i + 1);
}

void	fill_map(t_map *map, t_sqr big_sqr)
{
	int	i;
	int	j;

	i = 0;
	while (i < big_sqr.size)
	{
		j = 0;
		while (j < big_sqr.size)
		{
			map->map[big_sqr.pos_row + i][big_sqr.pos_col + j] = map->full;
			j++;
		}
		i++;
	}
}

int	compare_squares(t_map *map, int row, int col, t_sqr *big_sqr)
{
	int	found_size;

	found_size = get_square_size(map, row, col);
	if (found_size > big_sqr->size)
	{
		big_sqr->size = found_size;
		big_sqr->pos_col = col;
		big_sqr->pos_row = row;
	}
	return (found_size);
}

void	display_map(t_map	*map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		write (1, map->map[i], map->width);
		write (1, "\n", 1);
		i++;
	}
	//free_map(map);
}

int	solve(t_map *map)
{
	int		row;
	int		col;
	t_sqr	big_sqr;

	big_sqr.size = 0;
	big_sqr.pos_row = 0;
	big_sqr.pos_col = 0;
	row = 0;
	while (row < map->height - big_sqr.size)
	{
		col = 0;
		while (col < map->width - big_sqr.size)
		{
			if (map->map[row][col] == map->emp)
				col += compare_squares(map, row, col, &big_sqr);
			else
				col++;
		}
		row++;
	}
	fill_map(map, big_sqr);
	display_map(map);
	return (1);
}
