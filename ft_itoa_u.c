/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:02:38 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 12:31:21 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_positive(unsigned int n)
{
	char			*c;
	unsigned int	num;
	int				i;
	int				j;

	num = n;
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

char	*ft_itoa_u(unsigned int n)
{
	char *c;

	if ((n > 0 && n <= 9) || n == 0)
	{
		c = (char*)malloc(2 * sizeof(char));
		if (c == NULL)
			return (NULL);
		c[0] = n + '0';
		c[1] = '\0';
	}
	if (n > 9)
		c = if_positive(n);
	return (c);
}
