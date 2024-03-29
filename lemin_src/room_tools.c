/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 21:12:39 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 19:16:03 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_is_room(t_lemin *lem, char *line)
{
	char **split;

	if (ft_count_char(line, ' ') > 2)
		return (0);
	if (!(split = ft_strsplit(line, ' ')))
		exit(EXIT_FAILURE);
	if (!split[0] || !split[1] || !split[2] || split[3] ||
		*split[0] == 'L' || !ft_is_digit_str(split[1]) ||
		!ft_is_digit_str(split[2]) || ft_room_exist(lem, split[0]))
	{
		ft_free_split(split);
		return (0);
	}
	ft_free_split(split);
	return (1);
}

void	ft_add_rooms(t_lemin *lem, char *line)
{
	if (lem->cmd & START)
	{
		if (lem->start)
			ft_error(5);
		lem->start = ft_new_room(lem, line);
		lem->cmd ^= START;
	}
	else if (lem->cmd & END)
	{
		if (lem->end)
			ft_error(6);
		lem->end = ft_new_room(lem, line);
		lem->cmd ^= END;
	}
	else
		ft_new_room(lem, line);
}

t_room	*ft_new_room(t_lemin *lem, char *line)
{
	char	**split;
	t_room	*tmp;

	if (!(split = ft_strsplit(line, ' ')))
		exit(EXIT_FAILURE);
	tmp = lem->lst_room;
	if (!(lem->lst_room = (t_room *)malloc(sizeof(*tmp))))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	lem->lst_room->name = ft_strdup(split[0]);
	lem->lst_room->x = ft_atoi(split[1]);
	lem->lst_room->y = ft_atoi(split[2]);
	lem->lst_room->checked = 0;
	lem->lst_room->link = NULL;
	lem->lst_room->next = tmp;
	ft_free_split(split);
	return (lem->lst_room);
}

int		ft_room_exist(t_lemin *lem, char *line)
{
	t_room *tmp;

	tmp = lem->lst_room;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, line))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
