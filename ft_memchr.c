/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:34:45 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 10:41:39 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ch;
	unsigned char *fo;

	ch = (unsigned char*)s;
	while (n)
	{
		if (*ch == (unsigned char)c)
		{
			fo = ch;
			return (fo);
		}
		n--;
		ch++;
	}
	return (NULL);
}
