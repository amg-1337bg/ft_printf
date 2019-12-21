/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:03:40 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 15:09:04 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*ptr;
	int		i;

	if (s == NULL)
		return (NULL);
	ptr = (char*)s;
	i = 0;
	if ((p = (char*)malloc((len + 1) * sizeof(char))) == NULL)
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
	free((void*)s);
	return (p);
}
