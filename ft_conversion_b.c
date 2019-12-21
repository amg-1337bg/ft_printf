/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:31:04 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 12:39:53 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*con_u(void *arg)
{
	char			*res;
	unsigned int	i;

	i = (unsigned int)arg;
	res = ft_itoa_u(i);
	return (res);
}

char	*con_x_upper(void *arg)
{
	char			*res;
	char			*arr;
	unsigned int	i;
	int				j;

	arr = "0123456789ABCDEF";
	i = (unsigned int)arg;
	res = ft_strdup("");
	if (i == 0)
		return (ft_strdup("0"));
	while (i > 0)
	{
		j = i % 16;
		i = i / 16;
		res = ft_charjoin_r(res, arr[j]);
	}
	res = ft_inverse(res);
	return (res);
}

char	*con_x(void *arg)
{
	char			*res;
	char			*arr;
	unsigned int	i;
	int				j;

	arr = "0123456789abcdef";
	i = (unsigned int)arg;
	res = ft_strdup("");
	if (i == 0)
		return (ft_strdup("0"));
	while (i > 0)
	{
		j = i % 16;
		i = i / 16;
		res = ft_charjoin_r(res, arr[j]);
	}
	res = ft_inverse(res);
	return (res);
}
