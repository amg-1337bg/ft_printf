/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:45:49 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 20:18:02 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*greater_op(char *param, int j, int *index_of, int neg_or_not)
{
	int		length;
	char	*res;

	res = NULL;
	length = ft_strlen(param);
	if (*index_of == 1 && param[0] != '%')
	{
		while ((j - length) > 0)
		{
			param = ft_charjoin_l('0', param);
			length++;
		}
	}
	res = ft_strjoin(res, param);
	if (neg_or_not == 1)
		res = ft_charjoin_l('-', res);
	return (res);
}

char	*lower_op(char *param, int j, int *index_of, int neg_or_not)
{
	int		length;
	char	*res;

	res = NULL;
	length = ft_strlen(param);
	if (*index_of == 1 && (j < 0 || ft_strncmp(param, "0", length) != 0))
	{
		if (ft_strncmp(param, "0x0", length) == 0)
			res = ft_substr(param, 0, 2);
		else
			res = param;
	}
	else
	{
		if (j < 0)
			res = param;
		else
			res = ft_substr(param, 0, j);
	}
	if (neg_or_not == 1)
		res = ft_charjoin_l('-', res);
	return (res);
}

char	space_zer(char *arg, int star_val, int zero, int j)
{
	char zero_or_space;

	zero_or_space = ' ';
	if (zero == 1 && star_val > 0 && (j < 0 || arg[0] == '%'))
		zero_or_space = '0';
	return (zero_or_space);
}

char	*min_wid_prec_op(int length, int star_val, char zero_or_space)
{
	char	*res;
	int		index;

	index = 0;
	if (((res = (char*)malloc((star_val - length + 1) * sizeof(char))) == NULL))
		return (NULL);
	while (length < star_val)
	{
		res[index] = zero_or_space;
		index++;
		length++;
	}
	res[index] = '\0';
	return (res);
}

void	min_precision(const char *s, va_list arg, int *i, int index_of)
{
	int		j;
	int		star_val;
	char	*con_ret;
	int		star_neg;
	int		zero;

	ignor_mi_sp(s, i, &star_neg);
	star_val = get_flag_value(s, i, arg, &zero);
	j = *i;
	while (s[j] != '.' && s[j] != '\0')
		j++;
	if (j == *i)
		con_ret = min_prec(s, arg, &j, &index_of);
	else
	{
		con_ret = min_prec(s, arg, &j, &index_of);
		if (star_val >= (int)ft_strlen(con_ret) && index_of == 1
				&& j == (int)ft_strlen(con_ret))
			zero = 0;
		if (star_neg == 1 && star_val > 0)
			star_val *= -1;
		con_ret = prec_min(con_ret, star_val, zero, j);
	}
	ft_putchar_fd(con_ret, 1, ft_strlen(con_ret));
	free(con_ret);
}
