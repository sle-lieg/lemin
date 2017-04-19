/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:23:28 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:10:04 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_crea_file(t_lemin *lem)
{
	t_conect	*tmp_file;
	t_room		*tmp_room;

	tmp_file = lem->room_file;
	lem->start->checked = 1;
	while (tmp_file)
	{
		tmp_room = ft_find_room(lem, tmp_file);
		tmp_room->tmp_link = tmp_room->link;
		while (tmp_room->tmp_link)
		{
			if (!ft_is_checked(lem, tmp_room->tmp_link))
				ft_add_to_file(lem, tmp_room->tmp_link);
			tmp_room->tmp_link = tmp_room->tmp_link->next;
		}
		tmp_file = tmp_file->next;
	}
}

int		ft_is_checked(t_lemin *lem, t_conect *room)
{
	t_room *tmp;

	tmp = ft_find_room(lem, room);
	if (tmp->checked)
		return (1);
	tmp->checked = 1;
	return (0);
}

void	ft_add_to_file(t_lemin *lem, t_conect *room)
{
	if (!(lem->last_roomfile->next = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->last_roomfile = lem->last_roomfile->next;
	lem->last_roomfile->name = room->name;
	lem->last_roomfile->next = NULL;
}

void	ft_init_roomfile(t_lemin *lem)
{
	if (!(lem->room_file = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->room_file->name = lem->start->name;
	lem->last_roomfile = lem->room_file;
	lem->room_file->next = NULL;
}

void	ft_uncheck_file(t_lemin *lem)
{
	t_room		*tmp;
	t_conect	*tmp_file;

	tmp_file = lem->room_file;
	while (tmp_file)
	{
		tmp = ft_find_room(lem, tmp_file);
		tmp->checked = 0;
		tmp_file = tmp_file->next;
	}
}
