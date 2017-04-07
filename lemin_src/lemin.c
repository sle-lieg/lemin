/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:44:47 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/29 21:44:49 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 	main(int argc, char **argv)
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
	ft_print_room(&lem);
	ft_destroy_lemin(&lem);
	return (0);
}

void 	ft_init_lem(t_lemin *lem)
{
	lem->nb_ants = -1;
	lem->nb_room = 0;
	lem->cmd = 0;
	lem->pars_map = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->lst_room = NULL;
	// lem->lst_link = NULL;
}

void 	ft_print_room(t_lemin *lem)
{
	t_room *tmp;
	t_pars_lst *tmp2;

	tmp = lem->lst_room;
	ft_printf("LST_ROOM\n");
	if (lem->start)
		ft_printf("start = %s %d %d\n", lem->start->name, lem->start->x, lem->start->y);
	if (lem->end)
		ft_printf("end = %s %d %d\n", lem->end->name, lem->end->x, lem->end->y);
	while (tmp)
	{
		ft_printf("%s %d %d\n", tmp->name, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	ft_printf("\nPARS_MAP\n");

	tmp2 = lem->pars_map;
	while (tmp2)
	{
		ft_printf("%s\n", tmp2->line);
		tmp2 = tmp2->next;
	}
}