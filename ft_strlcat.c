/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:20:28 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 21:28:23 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t i;
	size_t k;

	k = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (i);
	j = ft_strlen(dst);
	if (j >= size)
		return (i + size);
	size = size - j - 1;
	if (size > 0)
	{
		while (k < size && src[k] != '\0')
		{
			dst[j + k] = src[k];
			k++;
		}
		dst[j + k] = '\0';
	}
	return (j + i);
}
