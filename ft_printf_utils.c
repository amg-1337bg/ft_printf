/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:39:41 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/19 20:07:11 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*detect_perc(const char *s, int i)
{
	char	*res;
	int		index;
	int		j;

	index = i;
	j = 0;
	while (s[i] != '%' && s[i] != '\0')
		i++;
	if ((res = (char *)malloc(i + 1)) == NULL)
		return (ft_strdup(""));
	while (s[index] != '%' && s[index] != '\0')
	{
		res[j] = s[index];
		j++;
		index++;
	}
	res[j] = '\0';
	return (res);
}

void	ignor_mi_sp(const char *s, int *i, int *star_neg)
{
	*star_neg = 0;
	while ((s[*i] == '-' || s[*i] == ' ' || s[*i] == '0') && s[*i] != '\0')
	{
		if (ft_isdigit(s[*i + 1]) == 1 || ft_isalpha(s[*i + 1]) == 1
				|| s[*i + 1] == '*')
		{
			if (s[*i] == '-' && s[*i + 1] == '*')
			{
				*star_neg = 1;
				(*i)++;
			}
			return ;
		}
		(*i)++;
	}
}

int		get_flag_value(const char *s, int *i, va_list arg, int *zero)
{
	int j;

	j = 0;
	*zero = 0;
	if (s[*i] == '0')
	{
		(*i)++;
		*zero = 1;
	}
	if (ft_atoi(&s[*i]) != 0 || s[*i] == '*')
	{
		if (s[*i] == '*')
			j = va_arg(arg, int);
		else
			j = ft_atoi(&s[*i]);
	}
	return (j);
}

void	fill_print(char **param, int neg_or_not)
{
	if (neg_or_not == 1)
		*param = ft_charjoin_l('-', *param);
}

int		get_flag_value_p(const char *s, int *i, va_list arg)
{
	int j;

	j = 0;
	(*i)++;
	if (ft_atoi(&s[*i]) != 0 || s[*i] == '0' || s[*i] == '*')
	{
		if (s[*i] == '*')
			j = va_arg(arg, int);
		else
			j = ft_atoi(&s[*i]);
	}
	return (j);
}
