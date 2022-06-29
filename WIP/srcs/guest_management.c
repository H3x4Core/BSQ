/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guest_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:59:53 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/27 20:48:58 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

char	*read_funny_words(void)
{
	char	buffer[BUF_SIZE + 1];
	int		len;
	char	*str;

	len = 1;
	str = (char *)malloc(BUF_SIZE + 1);
	if (!str)
		return (0);
	while (len > 0)
	{
		len = read(0, buffer, BUF_SIZE);
		if (len > 0)
			ft_strcat(str, buffer);
	}
	return (str);
}
