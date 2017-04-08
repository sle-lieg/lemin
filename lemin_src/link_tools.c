/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:14:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/08 15:14:38 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void 	ft_add_link(t_lemin *lem, char *line)
{
	t_link *tmp;
	char **split;

	if (!(split = ft_strsplit(line, '-')))
		exit(EXIT_FAILURE);
	tmp = lem->lst_link;

	if (!(lem->lst_link = (t_link *)malloc(sizeof(*tmp))))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	lem->lst_link->origin = ft_strdup(split[0]);
	lem->lst_link->to = ft_strdup(split[1]);
	lem->lst_link->next = tmp;
	ft_free_split(split);
}

int 	ft_is_link(t_lemin *lem, char *line)
{
	char **split;

	if (ft_count_char(line, '-') != 1)
		return (0);
	if (!(split = ft_strsplit(line, '-')))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (!ft_room_exist(lem, split[0]) || !ft_room_exist(lem, split[1]))
	{
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}