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
	ft_find_way(&lem);
	ft_delete_extra(&lem);
	ft_print_way(&lem);
	ft_move_ants(&lem);

	// ft_destroy_lemin(&lem);
	return (0);
}

void 	ft_delete_extra(t_lemin *lem)
{
	t_file *tmp;

	tmp = lem->way;
	lem->way = lem->way->next;
	free(tmp);
}

void 	ft_init_lem(t_lemin *lem)
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
	// lem->lst_files = NULL;
}

