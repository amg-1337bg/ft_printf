/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:02:15 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 09:23:15 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *f, int c, size_t len)
{
	unsigned char *p;
	unsigned char cs;

	p = (unsigned char*)f;
	cs = (unsigned char)c;
	while (len)
	{
		*p = cs;
		p++;
		len--;
	}
	return (f);
}
