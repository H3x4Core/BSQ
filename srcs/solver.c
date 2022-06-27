/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouce <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:09 by marvin            #+#    #+#             */
/*   Updated: 2022/06/27 14:04:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

#include <stdlib.h>
#include <stdio.h>

int	get_square_size(t_map map, int row, int col)
{
	int	i = 0;
	
	while (i < map.height)
	{
		int	j = 0;
		// Check the next row
		while (j <= i && row + j < map.height)
		{
			if (map.map[row + i][col + j] == map.obs)
				return (i);
			j++;
		}
		j = 0;
		// Check the next col
		while (j <= i && col + j < map.width)
		{
			if (map.map[row + j][col + i] == map.obs)
				return (i);
			j++;
		}
		i++;
	}
	return (i + 1);
}

void	fill_map(t_map map, t_sqr big_sqr)
{
	int	i;
	int	j;

	i = 0;
	while (i < big_sqr.size)
	{
		j = 0;
		while (j < big_sqr.size)
		{
			printf("doing black magic fuckery\n");
			printf("replacing %c with %c\n", map.map[big_sqr.pos_row + i][big_sqr.pos_col + j], map.full);
			//map.map[big_sqr.pos_row + i][big_sqr.pos_col + j] = map.full;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	printf("ok lets go");

	t_map	map;

	char	**map_array;
	char	*line1 = ".........o.................";
	char	*line2 = "....o................o.....";
	char	*line3 = "............o..............";
	char	*line4 = "........o..................";
	char	*line5 = "....o......................";
	char	*line6 = "...............o...........";
	char	*line7 = "...........................";
	char	*line8 = "......o..............o.....";
	char	*line9 = "..o.......o................";


	map_array = (char **)malloc(1000);

	map_array[0] = line1;
	map_array[1] = line2;
	map_array[2] = line3;
	map_array[3] = line4;
	map_array[4] = line5;
	map_array[5] = line6;
	map_array[6] = line7;
	map_array[7] = line8;
	map_array[8] = line9;

	map.width = 27;
	map.height = 9;
	map.obs = 'o';
	map.emp = '.';
	map.full = 'x';
	map.map = map_array;

	t_sqr	big_sqr;
	big_sqr.size = 0;
	big_sqr.pos_row = 0;
	big_sqr.pos_col = 0;

	// Go the line one by one
	int	row = 0;
	int	col = 0;
	while (row < map.height - big_sqr.size)
	{
		col = 0;
		while (col < map.width - big_sqr.size)
		{
			int size = 0;
			if (map.map[row][col] == map.emp)
			{
				printf("we found a sqr in %d %d\n", row, col);
				int found_size = get_square_size(map, row, col);
				printf("The size is %d\n", found_size);
				if (found_size > big_sqr.size)
				{
					big_sqr.size = found_size;
					big_sqr.pos_col = col;
					big_sqr.pos_row = row;
				}
				col += found_size;
			}
			else
				col++;
			
		}
		row++;
	}

	printf("\nWe're done, here is the result :\n");
	printf("size = %d, pos = %d %d", big_sqr.size, big_sqr.pos_row, big_sqr.pos_col);

	fill_map(map, big_sqr);
	
	printf("\n----------------------------------------------------------------------------\n");
	for (int loop = 0; loop < map.height; loop++)
	{
		printf("%s\n", map.map[loop]);
	}
	



	return (0);
}