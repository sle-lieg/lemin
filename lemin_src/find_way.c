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
	ft_printf("##################### FIND WAY #################\n");

	ft_init_file(lem);
	ft_explore(lem, lem->start);
}

void 	ft_explore(t_lemin *lem, t_room *room)
{
	t_room *tmp_room;
	if (room)
		ft_printf("[[%s]]\n", room->name);

	if (!room)
		return ;
	if (!room->checked)
	{		
		ft_add_to_file(lem, room->name);
		room->checked = 1;
	}	
	if (room == lem->end)
	{
		ft_print_file(lem);
		ft_new_file(lem);
	}
	if (!room->tmp_link)
	{
		room->checked = 0;
		ft_pop_file(lem);
		room->tmp_link = room->link;
		if (lem->lst_files->room)
		{
			ft_explore(lem, ft_find_room(lem, lem->lst_files->last));
		}
	}
	else
	{
		tmp_room = ft_find_room(lem, room->tmp_link);
		room->tmp_link = room->tmp_link->next;
		if (!tmp_room->checked)
		{
			ft_explore(lem, tmp_room);
		}
		else
		{
			ft_explore(lem, room);
		}
	}
}

void 	ft_print_file(t_lemin *lem)
{
	t_conect *tmp;
	static int count = 0;

	tmp = lem->lst_files->room;
	ft_printf("LINK[%d] : ", count++);
	while (tmp)
	{
		ft_printf("%s->", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void 	ft_pop_file(t_lemin *lem)
{
	t_conect *tmp;

	tmp = lem->lst_files->room;
	if (tmp && !tmp->next)
	{
		free(lem->lst_files->last);
		lem->lst_files->last = NULL;		
		lem->lst_files->room = NULL;
	}
	else if (tmp)
	{
		while (tmp->next != lem->lst_files->last)
			tmp = tmp->next;
		free(lem->lst_files->last);
		lem->lst_files->last = tmp;
		lem->lst_files->last->next = NULL;
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

void 	ft_add_to_file(t_lemin *lem, char *name)
{
	if (!lem->lst_files->room)
	{
		if (!(lem->lst_files->room = malloc(sizeof(t_conect))))
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
		if (!(lem->lst_files->last->next = malloc(sizeof(t_conect))))
		{
			perror("");
			exit(EXIT_FAILURE);
		}		
		lem->lst_files->last = lem->lst_files->last->next;
		lem->lst_files->last->name = name;
		lem->lst_files->last->next = NULL;
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
	ft_copy_files(lem->lst_files, tmp->room);
}

void 	ft_copy_files(t_file *new, t_conect *old)
{
	t_conect *tmp;

	while (old)
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
		new->last->name = old->name;
		new->last->next = NULL;
		
		old = old->next;
	}
}

// void 	ft_explore(t_lemin *lem, char *room)
// {
// 	t_room *tmp;

// 	tmp = ft_find_room(lem, room);	
// 	if (tmp)
// 	{
// 		ft_printf("TEST\n");
// 		ft_add_to_file(lem, room);
// 		// while (room->link)
// 		// while (room != lem->end)
// 		// {
// 			if (ft_not_in_file(lem, room->link->name))
// 			{
// 				// if (!room->link->next)
// 					// ft_check_links(lem, room);

// 				ft_explore(lem, ft_find_room(lem, room->link));
// 			}
// 			else
// 			{
// 				ft_new_file(lem);
// 				ft_explore(lem, ft_find_room(lem, room->link->next));
// 			}
// 		// }
// 	}
// }

// void 	ft_explore(t_lemin *lem, t_room *room)
// {	
// 	if (room)
// 	{
// 		ft_printf("TEST\n");
// 		ft_add_to_file(lem, room->name);
// 		// while (room->link)
// 		// while (room != lem->end)
// 		// {
// 		if (room->name)
// 		{
// 			if (ft_not_in_file(lem, room->link->name))
// 			{
// 				// if (!room->link->next)
// 					// ft_check_links(lem, room);

// 				ft_explore(lem, ft_find_room(lem, room->link));
// 			}
// 			else
// 			{
// 				ft_new_file(lem);
// 				ft_explore(lem, ft_find_room(lem, room->link->next));
// 			}
// 		}
// 	}
// }

// void 	ft_check_links(t_lemin *lem, t_room *room)
// {
// 	t_room 		*tmp;
// 	t_conect 	*tmp_co;

// 	tmp_co = room->link;
// 	while (tmp_co)
// 	{
// 		tmp = lem->tab_hash[ft_hash(lem->nb_room, tmp_co->name)];
// 		while (ft_strcmp(tmp->name, tmp_co->name))
// 			tmp = tmp->next;
// 		tmp->checked = 1;
// 		tmp_co = tmp_co->next;
// 	}
// }

// int 	ft_not_in_file(t_lemin *lem, char *name)
// {
// 	t_conect *tmp;

// 	tmp = lem->lst_files->room;
// 	while (tmp)
// 	{
// 		if (!ft_strcmp(tmp->name, name))
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// 	// aller a la fin de lem->lst_files->room
// 	//malloc lem->lst_files->room->next;
// 	//copy in lem->lst_files->room->name arg name
// 	// set lem->lst_files->room->next;
// // 	t_conect *tmp;

// // 	tmp = lem->lst_files->room;
// // 	if (!tmp)
// // 	{
// // 		if (!(tmp = malloc(sizeof(*tmp))))
// // 		{
// // 			perror("");
// // 			exit(EXIT_FAILURE);
// // 		}
// // 		tmp->name = name;
// // 		tmp->next = NULL;
// // 		lem->lst_files->room = tmp;
// // 	}
// // 	else
// // 	{
// // 		while (tmp->next)
// // 			tmp = tmp->next;
// // 		if (!(tmp->next = malloc(sizeof(*tmp))))
// // 		{
// // 			perror("");
// // 			exit(EXIT_FAILURE);
// // 		}
// // 		tmp->name = name;
// // 		tmp->next = NULL;
// // 	}
// // }

