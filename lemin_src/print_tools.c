/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:23:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/20 18:16:39 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_anthill(t_lemin *lem, int ant, char *name)
{
	if (lem->cmd & G)
	{
		if (ant % 6 == 0)
			ft_printf("{red}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
		else if (ant % 6 == 1)
			ft_printf("{green}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
		else if (ant % 6 == 2)
			ft_printf("{yellow}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
		else if (ant % 6 == 3)
			ft_printf("{blue}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
		else if (ant % 6 == 4)
			ft_printf("{purple}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
		else if (ant % 6 == 5)
			ft_printf("{grey}L%d{eoc}-{cyan}%s{eoc} ", ant, name);
	}
	else
		ft_printf("L%d-%s ", ant, name);
}

void	ft_print_map(t_lemin *lem)
{
	t_pars_lst *tmp;

	tmp = lem->pars_map;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

void	ft_print_options(t_lemin *lem)
{
	if (lem->cmd & H)
		ft_print_hashtab(lem);
	if (lem->cmd & C)
		ft_print_way(lem);
}

void	ft_print_way(t_lemin *lem)
{
	t_file		*tmp_file;
	t_conect	*tmp;
	int			count;

	count = 0;
	tmp_file = lem->way;
	tmp_file ? ft_printf("\n{blue}++++++++++ WAY ++++++++++{eoc}\n") : 0;
	while (tmp_file)
	{
		if (lem->cmd & G)
			ft_printf("{green}LINK[{red}%d{green}]{eoc} : ", count++);
		else
			ft_printf("LINK[%d] : ", count++);
		tmp = tmp_file->room;
		while (tmp)
		{
			lem->cmd & G ? ft_printf("{yellow}%s{eoc}", tmp->name) :
							ft_printf("%s", tmp->name);
			tmp = tmp->next;
			tmp ? ft_printf("->") : 0;
		}
		ft_printf("\n");
		tmp_file = tmp_file->next;
	}
}
