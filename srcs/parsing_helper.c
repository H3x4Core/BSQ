/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:00:27 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 14:24:49 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_map_height(char *str, int *nbr, int len)
{
	int	i;

	i = 0;
	*nbr = 0;
	len -= 3;
	while (ft_char_is_numeric(str[i]) && i < len)
	{
		*nbr *= 10;
		*nbr += (str[i] - '0');
		i++;
	}
	if (i != len)
		*nbr = 0;
	return (i);
}

int	get_map_length(char *str, int *len)
{
	int	i;

	i = 0;
	while (ft_char_is_printable(str[i]))
		i++;
	if (i)
		*len = i + 1;
	return (i);
}

int	get_map_char(char c, char *cmap)
{
	if (ft_char_is_printable(c))
		*cmap = c;
	else
		*cmap = 0;
	return (1);
}

int	get_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	return (i);
}

t_map	*error_map(t_map *map)
{
	if (map)
		free_map(map);
	write(2, "map error\n", 10);
	return (NULL);
}
