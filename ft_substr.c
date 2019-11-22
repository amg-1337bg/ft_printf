/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:03:40 by bamghoug          #+#    #+#             */
/*   Updated: 2019/10/29 11:01:10 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*p;
	unsigned char	*ptr;
	int				i;

	if (s == NULL)
		return (NULL);
	ptr = (unsigned char*)s;
	i = 0;
	p = (unsigned char*)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (ptr[start] != '\0' && len > 0)
		{
			p[i] = ptr[start];
			i++;
			start++;
			len--;
		}
	}
	p[i] = '\0';
	return ((char*)p);
}
