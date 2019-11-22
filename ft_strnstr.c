/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:49:05 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 22:33:17 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *n, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*n == '\0')
		return ((char*)hay);
	if (len == 0)
		return (NULL);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == n[j] && (j + i) < len)
		{
			j++;
			if (n[j] == '\0')
				return ((char*)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
