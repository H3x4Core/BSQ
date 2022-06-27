/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:49:35 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/27 14:39:46 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>	// open
# include <unistd.h> // close, read, write
# include <stdlib.h>	// malloc

# define BUF_SIZE 4096

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	char	obs;
	char	emp;
	char	full;
}			t_map;

typedef struct s_position
{
	int		col;
	int		row;
}			t_pos;

typedef struct s_square
{

    int    size;
    int    pos_row;
    int    pos_col;
}            t_sqr;

//read_file.c
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*read_file(char *filename);

//parsing.c

//ft_atoi.c
int	ft_char_is_numeric(char c);
int	ft_char_is_sign(char c);
int	ft_isspace(char c);
int	ft_atoi(char *str);

#endif

/**** DEBUG ****/
#ifndef DEBUG
# define DEBUG

#include <stdio.h>

#endif