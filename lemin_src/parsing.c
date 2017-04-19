/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:28:09 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:30:10 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_parse_lem(t_lemin *lem)
{
	ft_get_ants(lem);
	ft_get_rooms(lem);
	if (!lem->start || !lem->end)
	{
		ft_printf("Error : missing Start or End room.\n");
		exit(0);
	}
	ft_get_links(lem);
	ft_crea_hash_table(lem);
	ft_link_room(lem);
}

void	ft_get_ants(t_lemin *lem)
{
	char *line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
	{
		if (*line == '#')
			;
		else if (*line == '-' || !ft_is_digit_str(line) ||
				!ft_is_int_size(line))
		{
			ft_printf("Error : ant value invalid.\n");
			exit(0);
		}
		else
		{
			lem->nb_ants = ft_atoi(line);
			if (lem->nb_ants == 0)
			{
				ft_printf("Error : ant value invalid.\n");
				exit(0);
			}
			ft_map_list(lem, line);
			return ;
		}
	}
}

void	ft_get_rooms(t_lemin *lem)
{
	char *line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
	{
		if (*line == '#')
			ft_get_cmd(lem, line);
		else if (ft_is_room(lem, line))
		{
			ft_add_rooms(lem, line);
			lem->nb_room++;
			ft_map_list(lem, line);
		}
		else if (ft_is_link(lem, line))
		{
			ft_map_list(lem, line);
			ft_add_link(lem, line);
			break ;
		}
		else
		{
			ft_printf("Error : not enough data to create valid anthill.\n");
			exit(0);
		}
	}
}

void	ft_get_links(t_lemin *lem)
{
	char *line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
	{
		if (ft_is_link(lem, line))
		{
			ft_map_list(lem, line);
			ft_add_link(lem, line);
		}
		else if (*line == '#')
			ft_map_list(lem, line);
		else
			break ;
	}
	if (!lem->lst_link)
	{
		ft_printf("Error : not enough data to create valid anthill.\n");
		exit(0);
	}
}

void	ft_get_cmd(t_lemin *lem, char *line)
{
	ft_map_list(lem, line);
	if (!ft_strcmp(line, "##start") && !lem->start)
	{
		if (lem->cmd & END)
		{
			ft_printf("Error : same Start and End room.\n");
			exit(EXIT_FAILURE);
		}
		lem->cmd ^= START;
	}
	else if (!ft_strcmp(line, "##end") && !lem->end)
	{
		if (lem->cmd & START)
		{
			ft_printf("Error : same Start and End room.\n");
			exit(EXIT_FAILURE);
		}
		lem->cmd ^= END;
	}
}