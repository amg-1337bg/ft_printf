/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:28:44 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/19 11:55:44 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*con_s(void *arg)
{
	char *res;

	if (arg != NULL)
		res = ft_strdup((char *)arg);
	else
		res = ft_strdup("(null)");
	return (res);
}

char	*con_d_i(void *arg)
{
	char	*res;
	int		i;

	i = (int)arg;
	res = ft_itoa(i);
	return (res);
}

char	*con_c(void *arg)
{
	char *res;
	char c;

	res = malloc(2 * sizeof(char));
	c = (int)arg;
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*con_p(void *arg)
{
	char			*res;
	unsigned long	dec;
	int				j;
	int				i;
	char			*arr;

	arr = "0123456789abcdef";
	i = 0;
	res = ft_strdup("");
	dec = (unsigned long)arg;
	if (dec == 0)
		res = ft_strdup("0");
	while (dec > 0)
	{
		j = dec % 16;
		dec = dec / 16;
		res = ft_charjoin_r(res, arr[j]);
	}
	res = ft_strjoin(res, ft_strdup("x0"));
	res = ft_inverse(res);
	return (res);
}

char	*which_con(char c, va_list arg, int *index_of)
{
	char *res;

	*index_of = 0;
	res = NULL;
	if (c == 's')
		res = con_s(va_arg(arg, void*));
	else if (c == 'd' || c == 'i')
		res = con_d_i(va_arg(arg, void*));
	else if (c == 'c')
		res = con_c(va_arg(arg, void*));
	else if (c == 'p')
		res = con_p(va_arg(arg, void*));
	else if (c == 'u')
		res = con_u(va_arg(arg, void*));
	else if (c == 'x')
		res = con_x(va_arg(arg, void*));
	else if (c == 'X')
		res = con_x_upper(va_arg(arg, void*));
	else if (c == '%')
		res = ft_charjoin_r(res, '%');
	if (c == 'd' || c == 'i' || c == 'c' || c == 'p' || c == 'u' || c == 'x'
			|| c == 'X' || c == '%')
		*index_of = 1;
	return (res);
}
