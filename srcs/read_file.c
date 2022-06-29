/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 14:17:24 by mpouce           ###   ########.fr       */
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
	printf("maybe its a buffer issue.\n"); // DEBUG
	char	buffer[BUF_SIZE + 1];
	int		fd;
	int		len;
	char	*str;

	write (1, "reading file\n", 13); // DEBUG
	len = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	str = malloc(5000000000);
	while (len > 0)
	{
		len = read(fd, buffer, BUF_SIZE);
		printf("len = %d\n", len); // DEBUG
		printf("%s\n", buffer); // DEBUG
		str = ft_strcat(str, buffer);
	}
	printf("\nfinal shit : %s\n", str);
	close(fd);
	if (!str)
		return (0);
	/*if (!len)
	{
		free(str);
		return (0);
	}*/
	printf("readfile is done"); // DEBUG
	//ft_strncpy(str, buffer, len);
	return (str);
}

t_map	*free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}
