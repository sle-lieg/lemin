#include "lemin.h"

void 	ft_crea_ways(t_lemin *lem)
{
	t_conect *tmp_f;

	while (lem->room_file)
	{
		ft_new_way(lem);
		tmp_f = lem->room_file;
		while (tmp_f)
		{
			if (ft_is_conected(lem, tmp_f))
				ft_add_way(lem, tmp_f);
			if (ft_co_to_end(lem))
			{
				// ft_print_way(lem);

				// ft_add_way(lem, lem->end);
				ft_print_file(lem);

				ft_delete_dup_file(lem);
				break ;
			}
			else if (!tmp_f->next)
			{
				if (!(tmp_f = ft_pop_way(lem)))
					return ;
				ft_print_way(lem);
			}
			tmp_f = tmp_f->next;
		}
	}
}

void 	ft_uncheck(t_lemin *lem, t_conect *room)
{
	t_room *tmp;

	tmp = ft_find_room(lem, room);
	tmp->checked = 0;
}

t_conect *ft_pop_way(t_lemin *lem)
{
	t_conect *tmp_file;
	t_conect *tmp_way;

	tmp_file = lem->room_file;
	tmp_way = lem->way->room;
	while (ft_strcmp(lem->last_roomfile->name, tmp_file->name))
		tmp_file = tmp_file->next;
	while (tmp_way->next && tmp_way->next != lem->way->last)
		tmp_way = tmp_way->next;
	if (tmp_way == lem->way->last)
	{
		free(lem->way->last);
		lem->way->room = NULL;
		return (NULL);
	}
	ft_uncheck(lem, lem->way->last);
	free(lem->way->last);
	lem->way->last = tmp_way;
	lem->way->last->next = NULL;
	return (tmp_file);
}

// void 	ft_crea_ways(t_lemin *lem)
// {
// 	t_conect *tmp_f;

// 	while (lem->room_file)
// 	{
// 		ft_new_way(lem);
// 		tmp_f = lem->room_file;
// 		while (tmp_f)
// 		{
// 			if (ft_is_conected(lem, tmp_f))
// 				ft_add_way(lem, tmp_f);
// 			if (ft_co_to_end(lem))
// 			{
// 				// ft_print_way(lem);

// 				// ft_add_way(lem, lem->end);
// 				ft_print_file(lem);

// 				ft_delete_dup_file(lem);
// 				break ;
// 			}
// 			else if (tmp_f->next)
// 				tmp_f = tmp_f->next;
// 			else
// 			{			
// 				return ;
// 			}
// 		}
// 	}
// }

int 	ft_is_conected(t_lemin *lem, t_conect *tmp_f)
{
	t_room *tmp_room;

	tmp_room = ft_find_room(lem, tmp_f);
	tmp_room->tmp_link = tmp_room->link;
	while (tmp_room->tmp_link)
	{
		if (!ft_strcmp(tmp_room->tmp_link->name, lem->way->last->name))
		{
			if (!tmp_room->checked)
			{
				tmp_room->checked = 1;
				return (1);
			}
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