/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:50:16 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 21:11:19 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 1;
	map = 0;
	if (argc == 1)
	{
		map = parsing(read_funny_words());
		if (map)
			solve(map);
	}
	while (i < argc)
	{
		map = parsing(read_file(argv[i++]));
		if (map)
			solve(map);
	}
	return (0);
}
