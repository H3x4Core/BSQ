/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guest_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:59:53 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/29 14:18:05 by mpouce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	printf("Line to : %s\n", dest); // DEBUG
	printf("add line: %s\n", src); //DEBUG

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
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
