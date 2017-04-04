#include "lemin.h"

void 	ft_parse(t_lemin *lem)
{
	char *line;
	while (ft_get_next_line(0, &line))
	{
		if (ft_is_valid(line))
			ft_add_lstmap(lem, line);
		else
			break ;
	}
}

int 	ft_is_valid(char *str)
{
	//nombre fourmis == une chaine de digit;

	//chambre == "name", ' ', "digit", ' ', "digit".

	//connections == "name", '-', "name".

	//commandes == "##cmd"
	int i;

	i = 0;
	if (*str == '#' && *(str + 1) != '#')
		return (0);
	while (str[i])
	{
		if (str[i])
	}
}