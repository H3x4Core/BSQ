/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:49:35 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/29 14:27:48 by matwinte         ###   ########.fr       */
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
	char	***pmap;
	char	*meta_data;
	char	*line;
	int		width;
	int		height;
	char	obs;
	char	emp;
	char	full;
}			t_map;

typedef struct s_square
{
	int		size;
	int		pos_row;
	int		pos_col;
}			t_sqr;

/*
//read_file.c
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*read_file(char *filename);
t_map	*free_str(char *str);
*/
//parsing.c
/*
int		free_map(t_map *map);
int		create_blank_map(t_map *map);
int		get_map_info(t_map *map, int fd);
int		get_map_matrix(t_map *map, int fd);
t_map	*parsing(int fd);
*/

//parsing_v2.c - BERZERK EDITION
int		open_file(char *filename);
int		read_meta_data(int fd, int *len, t_map *map);
int		read_first_line(int fd, int *len, t_map *map);
int		read_middle_line(int fd, int *len, t_map *map);
int		read_last_line(int fd);
int		free_map(t_map *map);
int		create_blank_map(t_map *map);
void	get_meta_data(t_map *map, int len);
int		check_map_meta_data(t_map *map);
int		get_map_info(t_map *map, int fd);
int		matrix_line(t_map *map, int row);
int		get_map_matrix(t_map *map, int fd);
t_map	*parsing(int fd);

//parsing_helper.c
int		get_map_height(char *str, int *nbr, int len);
int		get_map_length(char *str, int *len);
int		get_map_char(char c, char *cmap);
int		get_line_len(char *str);
t_map	*error_map(t_map *map);

//parsing_utils.c
int		ft_char_is_numeric(char c);
int		ft_char_is_printable(char c);

//solver.c
int		get_square_size(t_map *map, int row, int col);
void	fill_map(t_map *map, t_sqr big_sqr);
int		compare_squares(t_map *map, int row, int col, t_sqr *big_sqr);
int		solve(t_map *map);

/*
//guest_management.c
char	*ft_strcat(char *dest, char *src);
char	*read_funny_words(void);
*/

#endif


/**DEBUG**/
#ifndef DEBUG
# define DEBUG

#include <stdio.h>
void	debug_print_map_info(t_map *map);
void	debug_print_map(t_map *map);

#endif
