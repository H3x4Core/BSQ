/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 20:36:18 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = 0;
	return (dest);
}

/* ************************************************************************** *
Read a file and return a string with the content of the file

Input:
	- char *filename : str containing the name of the file to open
Output:
	- char *str : whole file contained in a single string
* ************************************************************************** */
char	*read_file(char *filename)
{
	char	buffer[BUF_SIZE + 1];
	int		fd;
	int		len;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	len = read(fd, buffer, BUF_SIZE);
	close(fd);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[0] = 0;
	if (!len)
	{
		free(str);
		return (0);
	}
	ft_strncpy(str, buffer, len);
	return (str);
}

t_map	*free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}
