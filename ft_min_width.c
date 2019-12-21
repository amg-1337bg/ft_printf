/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:19:19 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/19 20:27:10 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hm_ze_sp(int min, int max, int zero, int neg_or_not)
{
	char	space_or_zero;
	int		index;
	int		num_sp_ze;

	index = 0;
	space_or_zero = ' ';
	num_sp_ze = max - min;
	if (zero == 1 && max > 0)
		space_or_zero = '0';
	if (neg_or_not == 1)
		max--;
	while (num_sp_ze)
	{
		ft_putchar_fd(&space_or_zero, 1, 1);
		num_sp_ze--;
	}
}

void	minimal_width_pos(char *arg, int i, int zero, int neg_or_not)
{
	int j;

	j = ft_strlen(arg);
	if (g_length + i < 0)
	{
		g_length = -1;
		return ;
	}
	if (j >= i)
	{
		if (neg_or_not == 1)
			arg = ft_charjoin_l('-', arg);
	}
	else if (j < i)
	{
		if (neg_or_not == 1)
		{
			ft_putchar_fd("-", 1, 1);
			i--;
		}
		hm_ze_sp(j, i, zero, neg_or_not);
	}
	ft_putchar_fd(arg, 1, ft_strlen(arg));
	free(arg);
}

void	minimal_width_neg(char *arg, int i, int zero, int neg_or_not)
{
	int j;

	j = ft_strlen(arg);
	if (g_length + (i = i * -1) < 0)
	{
		g_length = -1;
		return ;
	}
	if (j >= i)
	{
		if (neg_or_not == 1)
			arg = ft_charjoin_l('-', arg);
		ft_putchar_fd(arg, 1, ft_strlen(arg));
	}
	else if (j < i)
	{
		if (neg_or_not == 1)
		{
			ft_putchar_fd("-", 1, 1);
			i--;
		}
		ft_putchar_fd(arg, 1, ft_strlen(arg));
		hm_ze_sp(j, i, zero, neg_or_not);
	}
	free(arg);
}

void	min_width(const char *s, va_list arg, int *i, int index_of)
{
	int		j;
	int		zero;
	int		neg_or_not;
	char	*param;
	int		star_neg;

	ignor_mi_sp(s, i, &star_neg);
	j = get_flag_value(s, i, arg, &zero);
	while (ft_isalpha(s[*i]) == 0 && s[*i] != '%')
		(*i)++;
	if (star_neg == 1 && j > 0)
		j *= -1;
	param = which_con(s[*i], arg, &index_of);
	change_glob_int(s[*i], param, &j, index_of);
	check_arg(&param, &neg_or_not, zero);
	if (j > 0)
		minimal_width_pos(param, j, zero, neg_or_not);
	else if (j < 0)
		minimal_width_neg(param, j, zero, neg_or_not);
	else
	{
		fill_print(&param, neg_or_not);
		ft_putchar_fd(param, 1, ft_strlen(param));
		free(param);
	}
}
