/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:32:43 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:32:47 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_map_list(t_lemin *lem, char *line)
{
	static t_pars_lst *last = NULL;

	if (last)
	{
		if (!(last->next = (t_pars_lst *)malloc(sizeof(*last))))
			exit(EXIT_FAILURE);
		last = last->next;
		last->line = ft_strdup(line);
		last->next = NULL;
	}
	else
	{
		if (!(last = (t_pars_lst *)malloc(sizeof(*last))))
			exit(EXIT_FAILURE);
		last->line = ft_strdup(line);
		last->next = NULL;
		lem->pars_map = last;
	}
}

void	ft_destroy_lemin(t_lemin *lem)
{
	t_room		*tmp_r;
	t_pars_lst	*tmp_p;

	tmp_p = lem->pars_map;
	tmp_r = lem->lst_room;
	// while (tmp_r)
	// {
	// 	// ft_destroy_links(tmp_r->link);
	// 	free(tmp_r->name);
	// 	lem->lst_room = lem->lst_room->next;
	// 	free(tmp_r);
	// 	tmp_r = lem->lst_room;
	// }
	while (tmp_p)
	{
		free(tmp_p->line);
		lem->pars_map = lem->pars_map->next;
		free(tmp_p);
		tmp_p = lem->pars_map;
	}
	ft_destroy_links(lem->lst_link);
}

void 	ft_destroy_links(t_link *tmp_l)
{
	t_link *start;

	start = tmp_l;
	while (tmp_l)
	{
		free(tmp_l->origin);
		free(tmp_l->to);
		start = start->next;
		free(tmp_l);
		tmp_l = start;
	}
}
