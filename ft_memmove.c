/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:50:03 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 16:24:57 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == s)
		return (dst);
	if (src < dst)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	while (len)
	{
		d[i] = s[i];
		i++;
		len--;
	}
	return (dst);
}
