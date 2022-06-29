/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:50:16 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 16:05:54 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;
	int		fd;

	i = 1;
	fd = 0;
	if (argc == 1)
	{
		map = parsing(fd);
		if (map)
			solve(map);
	}
	while (i < argc)
	{
		fd = open_file(argv[i++]);
		map = parsing(fd);
		close(fd);
		if (map)
		{
			solve(map);
		}
		if (argc != 1 && i != argc)
			write(1, "\n", 1);
	}
	return (0);
}
