/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:50:16 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 08:48:13 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;
	int		fd;

	i = 1;
	fd = 0;
	if (argc == 1)
	{
		parsing(fd, &map);
		solve(&map);
	}
	while (i < argc)
	{
		fd = open_file(argv[i++]);
		parsing(fd, &map);
		close(fd);
		solve(&map);
		if (argc != 1 && i != argc)
			write(1, "\n", 1);
	}
	return (0);
}
