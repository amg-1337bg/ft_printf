/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:14:41 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 21:25:00 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		k;

	k = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	j = ft_strlen(dst);
	while (size > 1 && src[k] != '\0')
	{
		dst[k] = src[k];
		k++;
		size--;
	}
	dst[k] = '\0';
	return (i);
}
