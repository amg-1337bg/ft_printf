/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_occur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:54:18 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 20:43:27 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_founded(const char *s, va_list arg, int *i)
{
	int j;
	int	index_of;

	(*i)++;
	j = *i;
	index_of = 0;
	while (ft_isalpha(s[j]) == 0 && s[j] != '%')
		j++;
	if (check_precision(s, i) == 1)
		min_precision(s, arg, i, index_of);
	else if (ft_atoi(&s[*i]) != 0 || s[*i] == '0' || s[*i] == '-'
			|| s[*i] == '*' || s[*i] == ' ')
		min_width(s, arg, i, index_of);
	*i = j + 1;
}

void	conv_occur(const char *s, va_list arg, int *i)
{
	int		index_of;
	int		fake;
	char	*param;

	index_of = 0;
	fake = 1;
	if (ft_isalpha(s[*i + 1]) == 1 || s[*i + 1] == '%')
	{
		param = which_con(s[*i + 1], arg, &index_of);
		change_glob_int(s[*i + 1], param, &fake, index_of);
		ft_putchar_fd(param, 1, ft_strlen(param));
		*i += 2;
		free(param);
	}
	else
		flag_founded(s, arg, i);
}

void	modify_res(char **res, char *arg, int neg_or_not, int arg_neg_or_not)
{
	if (neg_or_not == 0)
		*res = ft_strjoin(*res, arg);
	else
		*res = ft_strjoin(arg, *res);
	if (arg_neg_or_not == 1)
		*res = ft_charjoin_l('-', *res);
}
