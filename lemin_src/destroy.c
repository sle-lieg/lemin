/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:16:21 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 19:08:35 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_destroy_lemin(t_lemin *lem)
{
	ft_destroy_tab_hash(lem);
	ft_destroy_links(lem->lst_link);
	ft_destroy_map(lem->pars_map);
	ft_destroy_way(lem);
}

void	ft_destroy_way(t_lemin *lem)
{
	t_file		*tmp;
	t_conect	*tmp_r;

	while (lem->way)
	{
		while (lem->way->room)
		{
			tmp_r = lem->way->room->next;
			free(lem->way->room);
			lem->way->room = tmp_r;
		}
		tmp = lem->way->next;
		free(lem->way);
		lem->way = tmp;
	}
}

void	ft_destroy_map(t_pars_lst *map)
{
	t_pars_lst *tmp;

	while (map)
	{
		tmp = map->next;
		free(map->line);
		free(map);
		map = tmp;
	}
}

void	ft_destroy_tab_hash(t_lemin *lem)
{
	int		i;
	t_room	*tmp;

	i = 0;
	while (i < lem->nb_room)
	{
		while (lem->tab_hash[i])
		{
			tmp = lem->tab_hash[i]->next;
			ft_free_roomlinks(lem->tab_hash[i]->link);
			free(lem->tab_hash[i]->name);
			free(lem->tab_hash[i]);
			lem->tab_hash[i] = tmp;
		}
		i++;
	}
	free(lem->tab_hash);
}

void	ft_free_roomlinks(t_conect *link)
{
	t_conect *tmp;

	while (link)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
}
