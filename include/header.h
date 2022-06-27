/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:49:35 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/27 13:51:55 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
	int		size;
	t_pos	pos;
}			t_sqr;

#endif

/**** DEBUG ****/
#ifndef DEBUG
# define DEBUG

#include <stdio.h>

#endif