/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:08:03 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 20:26:28 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_empty_char(int neg_or_not)
{
	if (neg_or_not == 1 && g_empty_char == 1)
	{
		g_empty_char = 0;
		ft_putchar_fd("", 1, 1);
	}
	if (neg_or_not == 0 && g_empty_char == 1)
		g_empty_char = -1;
}

void	check_ar(char **arg, int zero, int j, int *arg_neg_or_not)
{
	int	length;

	length = ft_strlen(*arg);
	if (*arg[0] == '-' && zero == 1 && j < 0)
	{
		*arg = ft_substr(*arg, 1, length);
		*arg_neg_or_not = 1;
	}
}
