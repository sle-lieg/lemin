/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:29:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/19 14:18:58 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_crea_hash_table(t_lemin *lem)
{
	t_room	*tmp;
	t_room	*prev;
	int		index;

	ft_init_hash(lem);
	tmp = lem->lst_room;
	while (tmp)
	{
		index = ft_hash(lem->nb_room, tmp->name);
		prev = lem->tab_hash[index];
		lem->tab_hash[index] = tmp;
		tmp = tmp->next;
		lem->tab_hash[index]->next = prev;
	}
}

void	ft_print_hashtab(t_lemin *lem)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (i < lem->nb_room)
	{
		tmp = lem->tab_hash[i];
		ft_printf("%d : ", i);
		while (tmp)
		{
			ft_printf("%s->", tmp->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_init_hash(t_lemin *lem)
{
	int i;

	i = 0;
	if (!(lem->tab_hash = (t_room **)malloc(sizeof(*lem->tab_hash) *
			lem->nb_room)))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	while (i < lem->nb_room)
		lem->tab_hash[i++] = NULL;
}

int		ft_hash(int nb_room, char *str)
{
	int key;
	int i;

	key = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		key = (key << 5) | (key >> 27);
		key += str[i];
		i++;
	}
	return (ABS(key % nb_room));
}
