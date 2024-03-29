/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:35:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/20 18:02:20 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_move_ants(t_lemin *lem)
{
	t_file	*tmp_way;
	int		ant;

	ant = 1;
	ft_printf("\n{blue}++++++++++ LEMINS_TRAVEL ++++++++++{eoc}");
	while (lem->end_ants < lem->nb_ants)
	{
		tmp_way = lem->way;
		while (tmp_way)
		{
			if (ant <= lem->nb_ants)
				ft_move(lem, tmp_way, ant++);
			else
				ft_move(lem, tmp_way, 0);
			tmp_way = tmp_way->next;
		}
		ft_print_ants(lem, lem->way);
		if (lem->end_ants < lem->nb_ants)
		{
			ft_printf("\n");
			lem->nb_move++;
		}
	}
}

void	ft_print_ants(t_lemin *lem, t_file *way)
{
	int		loop;
	t_file	*tmp_way;

	loop = 1;
	ft_set_to_print(way);
	while (loop)
	{
		tmp_way = way;
		loop = 0;
		while (tmp_way)
		{
			if (tmp_way->to_print && tmp_way->to_print->prev &&
					tmp_way->to_print->ant)
				ft_print_anthill(lem, tmp_way->to_print->ant,
					tmp_way->to_print->name);
			if (tmp_way->to_print)
				tmp_way->to_print = tmp_way->to_print->prev;
			if (tmp_way->to_print && tmp_way->to_print->ant)
				loop = 1;
			if (!tmp_way->next || !tmp_way->to_print || (tmp_way->to_print &&
			tmp_way->next->to_print &&
			tmp_way->to_print->ant > tmp_way->next->to_print->ant))
				tmp_way = tmp_way->next;
		}
	}
}

void	ft_move(t_lemin *lem, t_file *way, int n_ant)
{
	t_conect	*tmp;
	int			next_ant;

	tmp = way->room;
	while (tmp)
	{
		next_ant = tmp->ant;
		tmp->ant = n_ant;
		n_ant = next_ant;
		tmp = tmp->next;
		if (!tmp && next_ant > 0)
			lem->end_ants++;
	}
}

void	ft_set_to_print(t_file *way)
{
	while (way)
	{
		way->to_print = way->last;
		while (way->to_print && !way->to_print->ant)
			way->to_print = way->to_print->prev;
		way = way->next;
	}
}
