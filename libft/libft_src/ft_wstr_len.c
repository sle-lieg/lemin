/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-lieg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 00:08:22 by sle-lieg          #+#    #+#             */
/*   Updated: 2017/03/10 01:43:24 by sle-lieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstr_len(uint32_t *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str & FOUR)
			len += 4;
		else if (*str & THREE)
			len += 3;
		else if (*str & TWO)
			len += 2;
		else
			len++;
		str++;
	}
	return (len);
}
