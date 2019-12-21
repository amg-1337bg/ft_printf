/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:44:31 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/20 20:27:18 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(const char *c, int fd, int len)
{
	if (g_length + len < 0)
	{
		g_length = -1;
		return ;
	}
	g_length = write(fd, c, len) + g_length;
	if (g_empty_char == 1 && len == 0)
	{
		g_length = write(1, "", 1) + g_length;
		g_empty_char = 0;
	}
	if (g_empty_char == -1)
	{
		g_empty_char = 0;
		g_length = write(1, "", 1) + g_length;
	}
}
