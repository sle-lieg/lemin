/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:21:36 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/04/07 15:24:49 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_count_char(char *str, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i++] == c)
			n++;
	}
	return (n);
}
