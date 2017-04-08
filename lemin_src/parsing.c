#include "lemin.h"

void 	ft_parse_lem(t_lemin *lem)
{
	ft_get_ants(lem);
	ft_get_rooms(lem);
	ft_get_links(lem);
	ft_crea_hash_table(lem);
}

void 	ft_get_ants(t_lemin *lem)
{
	char *line;

	line = NULL;
	if (ft_get_next_line(0, &line) < 0 || *line == '-' ||
		!ft_is_digit_str(line) || !ft_is_int_size(line))
	{
		ft_printf("Error\n");
		exit(0);
	}
	ft_map_list(lem, line);
	lem->nb_ants = ft_atoi(line);
}

void 	ft_get_rooms(t_lemin *lem)
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
			break ;
	}
}

void 	ft_get_links(t_lemin *lem)
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
		// ft_get_cmd(lem, line);
		else
			break ;
	}
}

void 	ft_get_cmd(t_lemin *lem, char *line)
{
	ft_map_list(lem, line);
	if (!ft_strcmp(line, "##start") && !lem->start)
	{
		if (lem->cmd & END)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		lem->cmd ^= START;
	}
	else if (!ft_strcmp(line, "##end") && !lem->end)
	{
		if (lem->cmd & START)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		lem->cmd ^= END;
	}
}