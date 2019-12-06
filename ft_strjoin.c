/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:44:15 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/15 11:50:28 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL)
		return ((char *)s2);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = (char*)malloc((j + i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
