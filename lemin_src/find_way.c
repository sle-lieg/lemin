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
		ft_printf("LINK[%d] : ", count++);
		tmp = tmp_file->room;
		while (tmp)
		{
			ft_printf("%s->", tmp->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
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