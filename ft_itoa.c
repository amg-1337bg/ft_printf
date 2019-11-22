/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:45:24 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/01 16:55:45 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_neg(int n)
{
	char			*c;
	unsigned int	num;
	int				i;

	num = (unsigned int)(n * -1);
	n = n * -1;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	c = (char*)malloc((i + 2) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i--;
	c[i + 2] = '\0';
	while ((i + 1) > 0)
	{
		c[i + 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	c[i + 1] = '-';
	return (c);
}

char	*if_pos(int n)
{
	char	*c;
	long	num;
	int		i;
	int		j;

	num = (long)n;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	c = (char*)malloc((i + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i--;
	j = i + 1;
	while (i >= 0)
	{
		c[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char *c;

	if (n >= 0 && n <= 9)
	{
		c = (char*)malloc(2 * sizeof(char));
		if (c == NULL)
			return (NULL);
		c[0] = n + '0';
		c[1] = '\0';
	}
	if (n < 0)
		c = if_neg(n);
	if (n > 9)
		c = if_pos(n);
	return (c);
}
