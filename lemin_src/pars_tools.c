#include "lemin.h"

void 	ft_map_list(t_lemin *lem, char *line)
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
	//		LINKS
	//links == "name", '-', "name".
	//check if room exist when linking parsing.
	//check if one tiret in links.
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

void 	ft_destroy_lemin(t_lemin *lem)
{
	t_room 		*tmp_r;
	t_link 		*tmp_l;
	t_pars_lst	*tmp_p;

	tmp_p = lem->pars_map;
	tmp_r = lem->lst_room;
	tmp_l = lem->lst_link;
	while (tmp_r)
	{
		// ft_destroy_links(tmp_r->link);
		free(tmp_r->name);
		lem->lst_room = lem->lst_room->next;
		free(tmp_r);
		tmp_r = lem->lst_room;
	}
	while (tmp_l)
	{
		free(tmp_l->origin);
		free(tmp_l->to);
		lem->lst_link = lem->lst_link->next;
		free(tmp_l);
		tmp_l = lem->lst_link;
	}
	while (tmp_p)
	{
		free(tmp_p->line);
		lem->pars_map = lem->pars_map->next;
		free(tmp_p);
		tmp_p = lem->pars_map;
	}
}