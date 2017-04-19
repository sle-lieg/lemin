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

typedef struct 	s_conect
{
	char 				*name;
	int 				ant;
	struct s_conect 	*next;
	struct s_conect 	*prev;
}				t_conect;

typedef struct 	s_room
{
	char 				*name;
	int 				checked;
	int 				x;
	int 				y;
	t_conect 			*link;
	t_conect 			*tmp_link;
	struct s_room 		*next;
}				t_room;

typedef struct 	s_pars_lst
{
	char 				*line;
	struct s_pars_lst 	*next;
}				t_pars_lst;

typedef struct 	s_file
{
	struct s_conect		*room;
	struct s_conect		*to_print;
	struct s_conect		*last;
	struct s_file		*next;
}				t_file;

typedef struct 	s_lemin
{
	int 				nb_ants;
	int 				nb_room;
	int 				cmd;
	int 				end_ants;
	t_room				**tab_hash;
	t_room 				*start;
	t_room 				*end;
	t_room 				*lst_room;
	t_link				*lst_link;
	t_pars_lst 			*pars_map;

	t_conect 			*room_file;
	t_conect			*last_roomfile;
	t_file 				*way;
}				t_lemin;

/*
** /\/\/\/\/\ LEMIN.C /\/\/\/\/\
*/
void 					ft_init_lem(t_lemin *lem);
void 					ft_delete_extra(t_lemin *lem);

/*
** /\/\/\/\/\ PARSING.C /\/\/\/\/\
*/
void 					ft_parse_lem(t_lemin *lem);
void 					ft_get_ants(t_lemin *lem);
void 					ft_get_rooms(t_lemin *lem);
void 					ft_get_links(t_lemin *lem);
void 					ft_get_cmd(t_lemin *lem, char *line);

/*
** /\/\/\/\/\ PRINT_TOOLS.C /\/\/\/\/\
*/
void 					ft_print_room(t_lemin *lem);
void 					ft_print_way(t_lemin *lem);
void 					ft_print_file(t_lemin *lem);
void 					ft_print_map(t_lemin *lem);

/*
** /\/\/\/\/\ MOVE_ANTS.C /\/\/\/\/\
*/
void 					ft_move_ants(t_lemin *lem);
void 					ft_print_ants(t_file *way);
void 					ft_move(t_lemin *lem, t_file *way, int n_ant);
void 					ft_set_to_print(t_file *way);

/*
** /\/\/\/\/\ CREA_FILE.C /\/\/\/\/\
*/
void 	ft_crea_file(t_lemin *lem);
int 	ft_is_checked(t_lemin *lem, t_conect *room);
void 	ft_add_to_file(t_lemin *lem, t_conect *room);
void	ft_init_roomfile(t_lemin *lem);
void	ft_uncheck_file(t_lemin *lem);

/*
** /\/\/\/\/\ CREA_WAY.C /\/\/\/\/\
*/
void 	ft_crea_ways(t_lemin *lem);
int 	ft_is_conected(t_lemin *lem, t_conect *tmp_f);
void 	ft_add_way(t_lemin *lem, t_conect *tmp_f);
void 	ft_new_way(t_lemin *lem);
int 	ft_co_to_end(t_lemin *lem);


/*
** /\/\/\/\/\ FIND_WAY.C /\/\/\/\/\
*/
void 	ft_find_way(t_lemin *lem);
t_room *ft_find_room(t_lemin *lem, t_conect *link);
void 	ft_direct_way(t_lemin *way);
int 	ft_start_end_link(t_lemin *lem);

/*
** /\/\/\/\/\ ROOM_TOOLS.C /\/\/\/\/\
*/
void 	ft_add_rooms(t_lemin *lem, char *line);
t_room	*ft_new_room(t_lemin *lem, char *line);
int 	ft_is_room(t_lemin *lem, char *line);
int 	ft_room_exist(t_lemin *lem, char *line);

/*
** /\/\/\/\/\ LINK_TOOLS.C /\/\/\/\/\
*/
int 	ft_is_link(t_lemin *lem, char *line);
void 	ft_add_link(t_lemin *lem, char *line);
void 	ft_uncheck(t_lemin *lem, t_conect *room);
t_conect *ft_pop_way(t_lemin *lem);

/*
** /\/\/\/\/\ PARS_TOOLS.C /\/\/\/\/\
*/
void 	ft_map_list(t_lemin *lem, char *line);
void 	ft_destroy_lemin(t_lemin *lem);
void 	ft_destroy_links(t_link *tmp_l);

/*
** /\/\/\/\/\ HASH.C /\/\/\/\/\
*/
void 	ft_crea_hash_table(t_lemin *lem);
void 	ft_init_hash(t_lemin *lem);
int 	ft_hash(int nb_room, char *str);
void 	ft_print_hashtab(t_lemin *lem);

/*
** /\/\/\/\/\ LINK.C /\/\/\/\/\
*/
void 	ft_link_room(t_lemin *lem);
t_conect *ft_add_roomlink(char *name, t_conect *next);
int 	ft_check_if_link(t_conect *link, char *str);

#endif
