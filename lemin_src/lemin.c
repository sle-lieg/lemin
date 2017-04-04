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

	if (argc > 1)
	{
		ft_printf("Error : no argument nedded\n");
		return (0);
	}
	ft_init_lem(&lem);
	ft_parse(&lem);
	return (0);
}

void 	ft_init_lem(t_lemin *lem)
{
	lem->nb_ants = -1;
	lem->nb_room = 0;
	lem->cmd = 0;
	lem->pars_map = NULL;
}
