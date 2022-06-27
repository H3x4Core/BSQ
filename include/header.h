/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:49:35 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/27 17:09:17 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
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
int		free_map(t_map *map);
int		create_blank_map(t_map *map);
int		get_map_info(t_map *map, char *str);
int		get_map_matrix(t_map *map, char *str);
t_map	*parsing(char *filename);

//parsing_helper.c
int		get_map_height(char *str, int *nbr);
int		get_map_length(char *str, int *len);
int		get_map_char(char c, char *cmap);
int		get_next_line(char *str);

//parsing_utils.c
int		ft_char_is_numeric(char c);
int		ft_char_is_printable(char c);

#endif

/**** DEBUG ****/
#ifndef DEBUG
# define DEBUG

#include <stdio.h>

//_debug_parsing.c
void	debug_print_map_info(t_map *map);
void	debug_print_map(t_map *map);

#endif