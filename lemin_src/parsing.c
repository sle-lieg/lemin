#include "lemin.h"

void 	ft_parse(t_lemin *lem)
{
	ft_get_ants(lem);
	ft_get_rooms(lem);
	ft_get_links(lem);
}

void 	ft_get_ants(t_lemin *lem)
{
	//		ANTS
	//nombre fourmis == une chaine de digit sans espaces;
	//check if ants. (or negative ants).
	//check if ant nbr is int size.
	char *line;

	line = NULL;
	if (!ft_get_next_line(0, &line) || *line == '-' ||
		!ft_is_int_size(line) || !ft_is_digit_str(line))
	{
		ft_printf("Error ant value.\n");
		exit(EXIT_FAILURE);
	}
	lem->nb_ants = ft_atoi(line);
}
	
	while (ft_get_next_line(0, &line))
	{
		if (ft_is_ant(line) && lem->nb_ant == -1)
			lem->nb_ants = ft_atoi(line);
		else if (ft_is_room(line))
			ft_add_room(lem, line);
		else if (ft_is_link(line))
			ft_add_link(lem, line);
		else if (*line == '#')
			ft_get_cmd(lem, line);
		else
			break ;
	}

int 	ft_is_valid(char *str)
{
	//commandes == "##cmd"
	//check if valid command. (if ##).

	
	//		ROOMS
	//chambre == "name", ' ', "digit", ' ', "digit".
	//check duplicated name.
	//check nb de coordonees.
	//check if letter in coord.
	//check if start and end room.
	
	//		LINKS
	//links == "name", '-', "name".
	//check if room exist when linking parsing.
	//check if one tiret in links.
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i])
	}
}