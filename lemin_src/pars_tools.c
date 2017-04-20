/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:32:43 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 19:09:31 by sle-lieg         ###   ########.fr       */
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

void	ft_error(int code)
{
	if (code == 1)
		ft_printf("Error : missing Start or End room.\n");
	else if (code == 2)
		ft_printf("Error : ant value invalid.\n");
	else if (code == 3)
		ft_printf("Error : not enough data to create valid anthill.\n");
	else if (code == 4)
		ft_printf("Error : same Start and End room.\n");
	else if (code == 5)
		ft_printf("Error : multiple Start rooms.\n");
	else if (code == 6)
		ft_printf("Error : multiple End rooms.\n");
	else if (code == 7)
		ft_printf("usage : ./lem-in [-c -h] [< file]\n");
	exit(EXIT_FAILURE);
}

void	ft_destroy_links(t_link *tmp_l)
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
