/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:00:27 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 18:22:09 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_map_height(char *str, int *nbr, int len)
{
	int	i;

	i = 0;
	*nbr = 0;
	len -= 4;
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
		*len = i;
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

int	get_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}
