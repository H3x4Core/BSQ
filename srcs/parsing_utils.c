/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:59:26 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 17:08:52 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_char_is_numeric(char c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}

int	ft_char_is_printable(char c)
{
	if (c < ' ' || '~' < c)
		return (0);
	return (1);
}
