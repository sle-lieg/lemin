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

	ft_init_lem(&lem);
	if (argc > 1)
		ft_options(&lem, argc, argv);
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
		ft_print_options(&lem);
		ft_move_ants(&lem);
		if (lem.cmd & N)
			ft_printf("\nturns needed : |{green}%d{eoc}|\n", lem.nb_move - 1);
	}
	ft_destroy_lemin(&lem);
	return (0);
}

void 	ft_options(t_lemin *lem, int argc, char **argv)
{
	int i;

	while (--argc > 0)
	{
		i = 0;
		if (argv[argc][0] != '-')
			ft_error(7);
		while (argv[argc][++i])
		{
			if (argv[argc][i] == 'c')
				lem->cmd ^= C;
			else if (argv[argc][i] == 'h')
				lem->cmd ^= H;
			else if (argv[argc][i] == 'g')
				lem->cmd ^= G;
			else if (argv[argc][i] == 'n')
				lem->cmd ^= N;
			else
				ft_error(7);
		}
	}
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
	lem->nb_move = 0;
	lem->cmd = 0;
	lem->end_ants = 0;
	lem->tab_hash = NULL;
	lem->pars_map = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->lst_room = NULL;
	lem->lst_link = NULL;
	lem->way = NULL;
	lem->room_file = NULL;
	lem->last_roomfile = NULL;
}
