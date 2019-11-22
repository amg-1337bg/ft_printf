/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:59:51 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 21:02:42 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	cc;
	size_t			i;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	cc = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == cc)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
