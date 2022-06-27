/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:50:16 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 19:10:45 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main (void)
{
	t_map *map;
	char *str;
	char *filename = "./tools/map20x20_5";
	
	str = read_file(filename);
	map = parsing(str);
	if (!map)
		return (0);
	solve(map);
	return (0);
}
