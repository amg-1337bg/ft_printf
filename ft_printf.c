/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:59:45 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 08:53:03 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			final_len;

	va_start(ap, s);
	looking_for_conv(s, ap);
	if (g_length < 0)
		g_length = -1;
	final_len = g_length;
	g_length = 0;
	va_end(ap);
	return (final_len);
}
