/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:02:05 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/10 15:02:06 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_link_room(t_lemin *lem)
{
	t_link *tmp;
	t_room *room_select;

	tmp = lem->lst_link;
	while (tmp)
	{
		room_select = lem->tab_hash[ft_hash(lem->nb_room, tmp->origin)];		
		
		while (ft_strcmp(room_select->name, tmp->origin))
			room_select = room_select->next;		
		if (room_select != lem->end && !ft_check_if_link(room_select->link, tmp->to))
			room_select->link = ft_add_roomlink(tmp->to, room_select->link);
		room_select->tmp_link = room_select->link;
		room_select = lem->tab_hash[ft_hash(lem->nb_room, tmp->to)];
		while (ft_strcmp(room_select->name, tmp->to))
			room_select = room_select->next;
		if (room_select != lem->end && !ft_check_if_link(room_select->link, tmp->origin))
			room_select->link = ft_add_roomlink(tmp->origin, room_select->link);
		room_select->tmp_link = room_select->link;
		tmp = tmp->next;
	}
}

t_conect *ft_add_roomlink(char *name, t_conect *next)
{	
	t_conect *new;

	if (!(new = (t_conect *)malloc(sizeof(*new))))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	new->name = name;
	new->next = next;
	return (new);
}

int 	ft_check_if_link(t_conect *link, char *str)
{
	while (link)
	{
		if (!ft_strcmp(link->name, str))
			return (1);
		link = link->next;
	}
	return (0);
}