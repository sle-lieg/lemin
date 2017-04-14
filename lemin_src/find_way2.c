/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:06:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/11 15:06:23 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_print_way(t_lemin *lem)
{
	t_file *tmp_file;
	t_conect *tmp;
	int count = 0;

	tmp_file = lem->way;
	while (tmp_file)
	{
		printf("LINK[%d] : ", count++);
		tmp = tmp_file->room;
		while (tmp)
		{
			printf("%s->", tmp->name);
			tmp = tmp->next;
		}
		printf("\n");
		tmp_file = tmp_file->next;
	}
}

void	ft_print_file(t_lemin *lem)
{
	t_conect *tmp;

	tmp = lem->room_file;
	while (tmp)
	{
		ft_printf("%s - ", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");

}

void 	ft_find_way(t_lemin *lem)
{
	ft_init_roomfile(lem);
	ft_crea_file(lem);

	ft_uncheck_file(lem);

	ft_crea_ways(lem);

	ft_print_way(lem);
}

void	ft_uncheck_file(t_lemin *lem)
{
	t_room *tmp;
	t_conect *tmp_file;

	tmp_file = lem->room_file;
	while (tmp_file)
	{
		tmp = ft_find_room(lem, tmp_file);
		tmp->checked = 0;
		tmp_file = tmp_file->next;
	}
}

void	ft_init_roomfile(t_lemin *lem)
{
	if (!(lem->room_file = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->room_file->name = lem->start->name;
	lem->last_roomfile = lem->room_file;
	lem->room_file->next = NULL;
}

// ##### cra_file #####

int 	ft_is_checked(t_lemin *lem, t_conect *room)
{
	t_room *tmp;

	tmp = ft_find_room(lem, room);
	if (tmp->checked)
		return (1);
	tmp->checked = 1;
	return (0);
}

void 	ft_add_to_file(t_lemin *lem, t_conect *room)
{
	if (!(lem->last_roomfile->next = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->last_roomfile = lem->last_roomfile->next;
	lem->last_roomfile->name = room->name;
	lem->last_roomfile->next = NULL;
}

void 	ft_crea_file(t_lemin *lem)
{
	t_conect *tmp_file;
	t_room *tmp_room;

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

// ##### cra_ways #####


void 	ft_new_way(t_lemin *lem)
{
	t_file *tmp;

	tmp = lem->way;
	if (!(lem->way = (t_file *)malloc(sizeof(t_file))))
		exit(EXIT_FAILURE);
	lem->way->next = tmp;
	if (!(lem->way->room = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->way->last = lem->way->room;
	lem->way->room->name = lem->start->name;
	lem->way->room->next = NULL;
}

int 	ft_is_conected(t_lemin *lem, t_conect *tmp_f)
{
	t_room *tmp_room;

	tmp_room = ft_find_room(lem, tmp_f);
	tmp_room->tmp_link = tmp_room->link;
	while (tmp_room->tmp_link)
	{
		if (!ft_strcmp(tmp_room->tmp_link->name, lem->way->last->name))
		{
			tmp_room->checked = 1;
			return (1);
		}
		tmp_room->tmp_link = tmp_room->tmp_link->next;
	}
	return (0);
}

void 	ft_add_way(t_lemin *lem, t_conect *tmp_f)
{
	if (!(lem->way->last->next = (t_conect *)malloc(sizeof(t_conect))))
		exit(EXIT_FAILURE);
	lem->way->last = lem->way->last->next;
	lem->way->last->name = tmp_f->name;
	lem->way->last->next = NULL;
}

int 	ft_co_to_end(t_lemin *lem)
{
	t_room *tmp_room;

	tmp_room = ft_find_room(lem, lem->way->last);
	tmp_room->tmp_link = tmp_room->link;
	while (tmp_room->tmp_link)
	{
		if (!ft_strcmp(tmp_room->tmp_link->name, lem->end->name))
			return (1);
		tmp_room->tmp_link = tmp_room->tmp_link->next;
	}
	return (0);	
}

void 	ft_delete_dup_file(t_lemin *lem)
{
	t_conect 	*tmp_f;
	t_conect 	*to_free;
	t_room 		*tmp_r;

	// static int c = 0;

	tmp_f = lem->room_file;

	while (tmp_f && tmp_f->next)
	{
		// ft_printf("{%d}\n", c++);

		tmp_r = ft_find_room(lem, tmp_f->next);
		if (tmp_r->checked)
		{
			to_free = tmp_f->next;
			tmp_f->next = to_free->next;
			free(to_free);
		}
		tmp_f = tmp_f->next;
	}

}

void 	ft_crea_ways(t_lemin *lem)
{
	t_conect *tmp_f;

	while (lem->room_file)
	{
		ft_new_way(lem);
		tmp_f = lem->room_file;
		while (tmp_f)
		{

			if (ft_is_conected(lem, tmp_f)) // verifie que tmp_f est connecter a last_way
				ft_add_way(lem, tmp_f);
			if (ft_co_to_end(lem))
			{
				// ft_print_way(lem);

				// ft_add_way(lem, lem->end);
				ft_print_file(lem);

				ft_delete_dup_file(lem);
				break ;
			}
			else if (tmp_f->next)
				tmp_f = tmp_f->next;
			else
			{			
				return ;
			}
		}
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