/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:28:15 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/10 17:28:16 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_find_way(t_lemin *lem)
{
	ft_init_file(lem);
	ft_explore(lem, lem->start);
}

void 	ft_explore(t_lemin *lem, t_room *room)
{	
	if (room && !room->checked)
	{
		// ft_printf("TEST\n");
		ft_add_to_file(lem, room->name);
		while (room->link)
		// while (room != lem->end)
		{
			if (ft_not_in_file(lem, room->link->name))
			{
				if (!room->link->next)
					ft_check_links(lem, room);

				ft_explore(lem, ft_find_room(lem, room->link));
			}
			else
			{
				ft_new_file(lem);
				ft_explore(lem, ft_find_room(lem, room->link->next));
			}
		}
	}
}

void 	ft_check_links(t_lemin *lem, t_room *room)
{
	t_room 		*tmp;
	t_conect 	*tmp_co;

	tmp_co = room->link;
	while (tmp_co)
	{
		tmp = lem->tab_hash[ft_hash(lem->nb_room, tmp_co->name)];
		while (ft_strcmp(tmp->name, tmp_co->name))
			tmp = tmp->next;
		tmp->checked = 1;
		tmp_co = tmp_co->next;
	}
}

void 	ft_new_file(t_lemin *lem)
{
	t_file *tmp;

	tmp = lem->lst_files;
	if (!(lem->lst_files = malloc(sizeof(*lem->lst_files))))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	lem->lst_files->next = tmp;
	lem->lst_files->room = NULL;
	ft_copy_files(lem->lst_files, tmp);
}

void 	ft_copy_files(t_file *new, t_file *old)
{
	t_conect *tmp;

	while (old->room)
	{
		tmp = new->room;
		if (!tmp)
		{
			if (!(new->room = malloc(sizeof(*new->room))))
			{
				perror("");
				exit(EXIT_FAILURE);
			}
			new->last = new->room;
		}
		else
		{
			if (!(new->last->next = malloc(sizeof(*new->last))))
			{
				perror("");
				exit(EXIT_FAILURE);
			}
			new->last = new->last->next;
		}
		new->last->name = old->room->name;
		new->last->next = NULL;
		
		old->room = old->room->next;
	}
}

t_room *ft_find_room(t_lemin *lem, t_conect *link)
{
	t_room *tmp;

	if (!link)
		return (NULL);
	tmp = lem->tab_hash[ft_hash(lem->nb_room, link->name)];
	while (ft_strcmp(link->name, tmp->name))
		tmp = tmp->next;
	return (tmp);
}

int 	ft_not_in_file(t_lemin *lem, char *name)
{
	t_conect *tmp;

	tmp = lem->lst_files->room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void 	ft_add_to_file(t_lemin *lem, char *name)
{
	if (!lem->lst_files->last)
	{
		if (!(lem->lst_files->room = malloc(sizeof(*lem->lst_files->room))))
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		lem->lst_files->room->name = name;
		lem->lst_files->room->next = NULL;
		lem->lst_files->last = lem->lst_files->room;
	}
	else
	{
		if (!(lem->lst_files->last->next = malloc(sizeof(*lem->lst_files->last))))
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		lem->lst_files->last = lem->lst_files->last->next;
		lem->lst_files->last->name = name;
		lem->lst_files->last->next = NULL;
	}
}
	// aller a la fin de lem->lst_files->room
	//malloc lem->lst_files->room->next;
	//copy in lem->lst_files->room->name arg name
	// set lem->lst_files->room->next;
// 	t_conect *tmp;

// 	tmp = lem->lst_files->room;
// 	if (!tmp)
// 	{
// 		if (!(tmp = malloc(sizeof(*tmp))))
// 		{
// 			perror("");
// 			exit(EXIT_FAILURE);
// 		}
// 		tmp->name = name;
// 		tmp->next = NULL;
// 		lem->lst_files->room = tmp;
// 	}
// 	else
// 	{
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		if (!(tmp->next = malloc(sizeof(*tmp))))
// 		{
// 			perror("");
// 			exit(EXIT_FAILURE);
// 		}
// 		tmp->name = name;
// 		tmp->next = NULL;
// 	}
// }

void 	ft_init_file(t_lemin *lem)
{
	if (!(lem->lst_files = malloc(sizeof(*lem->lst_files))))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	lem->lst_files->room = NULL;
	lem->lst_files->last = NULL;
	lem->lst_files->next = NULL;
}