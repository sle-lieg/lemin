/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:23:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/17 13:23:24 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_print_map(t_lemin *lem)
{
	t_pars_lst *tmp;

	tmp = lem->pars_map;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

void 	ft_print_room(t_lemin *lem)
{
	int i;
	t_pars_lst *tmp2;
	t_conect *tmp3;

	i = 0;
	tmp2 = lem->pars_map;
	ft_printf("nb room = %d\n", lem->nb_room);
	ft_printf("nb ants = %d\n", lem->nb_ants);
	ft_printf("PARS_MAP\n");
	while (tmp2)
	{
		ft_printf("%s\n", tmp2->line);
		tmp2 = tmp2->next;
	}
	ft_printf("\nLST_ROOM\n");
	if (lem->start)
		ft_printf("start = %s %d %d\n", lem->start->name, lem->start->x, lem->start->y);
	if (lem->end)
		ft_printf("end = %s %d %d\n", lem->end->name, lem->end->x, lem->end->y);
	while (i < lem->nb_room)
	{
		if (lem->tab_hash[i])
		{
			tmp3 = lem->tab_hash[i]->link;
			ft_printf("%s %d %d\n", lem->tab_hash[i]->name, lem->tab_hash[i]->x, lem->tab_hash[i]->y);
			while (tmp3)
			{
				ft_printf("%s->", tmp3->name);
				tmp3 = tmp3->next;
			}
			ft_printf("\n");

		}
		i++;
	}
}

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