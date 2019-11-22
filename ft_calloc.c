/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:36 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/01 16:53:19 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			co;
	unsigned char	*p;

	co = count * size;
	p = (unsigned char*)malloc(co);
	if (p == NULL)
		return (NULL);
	if (co == 0)
		return (p);
	ft_bzero(p, co);
	return (p);
}
