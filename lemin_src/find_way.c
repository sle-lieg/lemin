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

void 	ft_find_way(t_lemin *lem)
{
	ft_init_roomfile(lem);
	ft_crea_file(lem);
	ft_uncheck_file(lem);
	if (ft_start_end_link(lem))
		ft_direct_way(lem);
	else
	{
		ft_crea_ways(lem);
		if (!lem->way->next)
		{
			ft_printf("Error\n");
			exit(0);
		}
		// ft_print_way(lem);
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

void 	ft_direct_way(t_lemin *lem)
{
	int ant;

	ant = 1;
	while (ant <= lem->nb_ants)
	{
		ft_printf("L%d-%s", ant, lem->end->name);
		if (ant++ < lem->nb_ants)
			ft_printf(" ");
	}
	ft_printf("\n");
}

int 	ft_start_end_link(t_lemin *lem)
{
	lem->start->tmp_link = lem->start->link;

	while (lem->start->tmp_link)
	{
		if (!ft_strcmp(lem->start->tmp_link->name, lem->end->name))
			return (1);
		lem->start->tmp_link = lem->start->tmp_link->next;
	}
	return (0);
}