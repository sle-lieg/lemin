/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:44:26 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/29 21:44:29 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

# define START 0x1
# define END 0x2

typedef struct 	s_link
{
	char 				*origin;
	char 				*to;
	struct s_link 		*next;
}				t_link;

typedef struct 	s_room
{
	char 				*name;
	int 				x;
	int 				y;
	t_link 				*link;
	struct s_room 		*next;
}				t_room;

typedef struct 	s_pars_lst
{
	char 				*line;
	struct s_pars_lst 	*next;
}				t_pars_lst;

typedef struct 	s_lemin
{
	int 				nb_ants;
	int 				nb_room;
	int 				cmd;

	t_room 				*start;
	t_room 				*end;
	t_room 				*lst_room;
	
	// t_link				*lst_link;

	t_pars_lst 			*pars_map;
}				t_lemin;

void 	ft_print_room(t_lemin *lem);


/*
** /\/\/\/\/\ LEMIN.C /\/\/\/\/\
*/
void 	ft_init_lem(t_lemin *lem);

/*
** /\/\/\/\/\ PARSING.C /\/\/\/\/\
*/
void 	ft_parse_lem(t_lemin *lem);
void 	ft_get_ants(t_lemin *lem);
void 	ft_get_rooms(t_lemin *lem);
void 	ft_get_links(t_lemin *lem);
void 	ft_get_cmd(t_lemin *lem, char *line);

/*
** /\/\/\/\/\ ROOM_TOOLS.C /\/\/\/\/\
*/
void 	ft_add_rooms(t_lemin *lem, char *line);
t_room	*ft_new_room(t_lemin *lem, char *line);
int 	ft_is_room(t_lemin *lem, char *line);
int 	ft_room_exist(t_lemin *lem, char *line);

/*
** /\/\/\/\/\ PARS_TOOLS.C /\/\/\/\/\
*/
void 	ft_map_list(t_lemin *lem, char *line);
int 	ft_is_link(t_lemin *lem, char *line);

#endif
