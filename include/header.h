/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:49:35 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/27 21:07:50 by matwinte         ###   ########.fr       */
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
t_map	*free_str(char *str);

//parsing.c
int		free_map(t_map *map);
int		create_blank_map(t_map *map);
int		get_map_info(t_map *map, char *str);
int		get_map_matrix(t_map *map, char *str);
t_map	*parsing(char *str);

//parsing_helper.c
int		get_map_height(char *str, int *nbr, int len);
int		get_map_length(char *str, int *len);
int		get_map_char(char c, char *cmap);
int		get_next_line(char *str);
t_map	*error_map(t_map *map, char *str);

//parsing_utils.c
int		ft_char_is_numeric(char c);
int		ft_char_is_printable(char c);

//solver.c
int		get_square_size(t_map *map, int row, int col);
void	fill_map(t_map *map, t_sqr big_sqr);
int		compare_squares(t_map *map, int row, int col, t_sqr *big_sqr);
int 	solve(t_map *map);

//guest_management.c
char	*ft_strcat(char *dest, char *src);
char	*read_funny_words(void);

#endif
