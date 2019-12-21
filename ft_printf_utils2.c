/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:01:52 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 09:15:38 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_glob_int(char c, char *param, int *j, int i_o_a)
{
	if (c == 'c' && i_o_a == 1 && ft_strncmp(param, "", 1) == 0)
	{
		if (*j < 0)
			(*j)++;
		else if (*j > 0)
			(*j)--;
		g_empty_char = 1;
	}
}

char	*min_prec(const char *s, va_list arg, int *i, int *index_of)
{
	char	*res;
	char	*param;
	int		j;
	int		neg_or_not;

	res = NULL;
	neg_or_not = 0;
	j = 0;
	j = get_flag_value_p(s, i, arg);
	while (ft_isalpha(s[*i]) == 0 && s[*i] != '\0' && s[*i] != '%')
		(*i)++;
	param = which_con(s[*i], arg, index_of);
	change_glob_int(s[*i], param, &j, *index_of);
	check_prec_arg(&param, &neg_or_not, index_of);
	if (j >= (int)ft_strlen(param))
		res = greater_op(param, j, index_of, neg_or_not);
	else if (j < (int)ft_strlen(param))
		res = lower_op(param, j, index_of, neg_or_not);
	*i = j;
	return (res);
}

char	*prec_min(char *arg, int star_val, int zero, int j)
{
	char	*res;
	int		length;
	int		neg_or_not;
	char	zero_or_space;
	int		arg_neg_or_not;

	neg_or_not = 0;
	res = ft_strdup("");
	length = ft_strlen(arg);
	arg_neg_or_not = 0;
	zero_or_space = space_zer(arg, star_val, zero, j);
	check_arg_p(arg, &star_val, &neg_or_not);
	check_ar(&arg, zero, j, &arg_neg_or_not);
	if (g_empty_char == 1)
		star_val -= 1;
	if (star_val > length)
	{
		free(res);
		res = min_wid_prec_op(length, star_val, zero_or_space);
		modify_res(&res, arg, neg_or_not, arg_neg_or_not);
		print_empty_char(neg_or_not);
	}
	return (res);
}

void	looking_for_conv(const char *s, va_list ap)
{
	int i;
	int last;

	i = 0;
	last = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_putchar_fd(&s[last], 1, i - last);
			conv_occur(s, ap, &i);
			last = i;
			if (g_length < 0)
				return ;
		}
		else
			i++;
	}
	ft_putchar_fd(&s[last], 1, i - last);
}
