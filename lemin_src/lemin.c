/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:44:47 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:20:29 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_lemin lem;

	(void)argv;
	if (argc > 1)
	{
		ft_printf("Error : no argument nedded\n");
		return (0);
	}
	ft_init_lem(&lem);
	ft_parse_lem(&lem);
	if (ft_start_end_link(&lem))
	{
		ft_print_map(&lem);
		ft_direct_way(&lem);
	}
	else
	{
		ft_find_way(&lem);
		ft_delete_extra(&lem);
		ft_print_map(&lem);
		ft_move_ants(&lem);
	}
	ft_destroy_lemin(&lem);
	return (0);
}

void	ft_delete_extra(t_lemin *lem)
{
	t_file *tmp;

	tmp = lem->way;
	lem->way = lem->way->next;
	free(tmp);
	tmp = lem->way;
	while (tmp)
	{
		if (!(tmp->last->next = (t_conect *)malloc(sizeof(t_conect))))
			exit(EXIT_FAILURE);
		tmp->last->next->prev = tmp->last;
		tmp->last = tmp->last->next;
		tmp->last->name = lem->end->name;
		tmp->last->ant = 0;
		tmp->last->next = NULL;
		tmp = tmp->next;
	}
}

void	ft_init_lem(t_lemin *lem)
{
	lem->nb_ants = 0;
	lem->nb_room = 0;
	lem->cmd = 0;
	lem->end_ants = 0;
	lem->pars_map = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->lst_room = NULL;
	lem->lst_link = NULL;
	lem->way = NULL;
	lem->room_file = NULL;
	lem->last_roomfile = NULL;
}
