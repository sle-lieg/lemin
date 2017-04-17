/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:35:57 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/17 15:35:59 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_move_ants(t_lemin *lem)
{
	t_file *tmp_way;
	int 	ant;

	ant = 1;

	while (lem->end_ants <= lem->nb_ants)
	{
		tmp_way = lem->way;
		while (tmp_way)
		{
			ft_move(lem, tmp_way, ant++);
			tmp_way = tmp_way->next;
		}
		tmp_way = lem->way;
		while (tmp_way)
		{
			ft_print_ants(tmp_way->room);
			tmp_way = tmp_way->next;
			if (tmp_way)
				ft_printf(" ");
		}
		ft_printf("\n");
	}
}

void 	ft_print_ants(t_conect *way)
{
	way = way->next;
	while (way)
	{
		if (way->ant)
			ft_printf("L%d-%s", way->ant, way->name);
		way = way->next;
		if (way && way->ant)
			ft_printf(" ");
	}
}

void 	ft_move(t_lemin *lem, t_file *way, int n_ant)
{
	t_conect 	*tmp;
	int 		next_ant;

	tmp = way->room;
	// next_ant = tmp->ant;
	// tmp->ant = n_ant;
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