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

# define START 0x1;
# define END 0x2;

typedef struct 	s_lemin
{
	int 		nb_ants;
	int 		nb_room;
	char 		cmd;
	s_pars_lst 	*pars_map;
}				t_lemin;

typedef struct 	s_pars_lst
{
	char 				*line;
	struct s_pars_lst 	*next;
}				t_pars_lst;

/*
** /\/\/\/\/\ PARSING.C /\/\/\/\/\
*/
void 	ft_parse(t_lemin *lem);

#endif
