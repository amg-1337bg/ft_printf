/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:13:01 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 18:18:09 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(char **arg, int *neg_or_not, int zero)
{
	*neg_or_not = 0;
	if (*arg[0] == '-' && zero == 1)
	{
		*neg_or_not = 1;
		*arg = ft_substr(*arg, 1, ft_strlen(*arg));
	}
}

void	check_prec_arg(char **param, int *neg_or_not, int *index_of)
{
	if (*param[0] == '-' && *index_of == 1)
	{
		*neg_or_not = 1;
		*param = ft_substr(*param, 1, ft_strlen(*param));
	}
}

void	check_arg_p(char *arg, int *star_val, int *neg_or_not)
{
	int length;

	length = ft_strlen(arg);
	if (*star_val < 0)
	{
		*neg_or_not = 1;
		*star_val *= -1;
	}
	if (*star_val <= length)
	{
		ft_putchar_fd(arg, 1, length);
		free(arg);
	}
}

int		check_precision(const char *s, int *i)
{
	int j;

	j = *i;
	while (ft_isalpha(s[j]) == 0 && s[j] != '\0')
	{
		if (s[j] == '.')
			return (1);
		j++;
	}
	return (0);
}
