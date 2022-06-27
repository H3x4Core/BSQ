/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:50:16 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 17:52:52 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main (void)
{
	t_map *map;
	char *str;
	char *filename = "./tools/map0";
	
	map = parsing(str);
	debug_print_map_info(map);
	debug_print_map(map);
	printf("\n-----\n\n");
	solve(map);
	debug_print_map(map);
}
