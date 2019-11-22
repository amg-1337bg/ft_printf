/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:39:21 by bamghoug          #+#    #+#             */
/*   Updated: 2019/10/28 12:51:08 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (*str == 32 || *str == 9 || *str == 11
			|| *str == 12 || *str == 13 || *str == 10)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = 1;
		str++;
	}
	if (*str < 48 && *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		j = j * 10 + *str - '0';
		str++;
	}
	if (i == 1)
		return (j * -1);
	return (j);
}
