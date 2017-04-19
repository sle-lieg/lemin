/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:14:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:24:10 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_add_link(t_lemin *lem, char *line)
{
	t_link	*tmp;
	char	**split;

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

int			ft_is_link(t_lemin *lem, char *line)
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

void		ft_uncheck(t_lemin *lem, t_conect *room)
{
	t_room *tmp;

	tmp = ft_find_room(lem, room);
	tmp->checked = 0;
}

t_conect	*ft_pop_way(t_lemin *lem)
{
	t_conect *tmp_file;
	t_conect *tmp_way;

	tmp_file = lem->room_file;
	tmp_way = lem->way->room;
	while (ft_strcmp(lem->way->last->name, tmp_file->name))
		tmp_file = tmp_file->next;
	while (tmp_way->next && tmp_way->next != lem->way->last)
		tmp_way = tmp_way->next;
	if (tmp_way == lem->way->last)
	{
		free(lem->way->last);
		lem->way->room = NULL;
		return (NULL);
	}
	ft_uncheck(lem, lem->way->last);
	free(lem->way->last);
	lem->way->last = tmp_way;
	lem->way->last->next = NULL;
	return (tmp_file);
}
