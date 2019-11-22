/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:25:09 by bamghoug          #+#    #+#             */
/*   Updated: 2019/10/29 08:15:17 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		trim_checker(char const *s1, char const *set, int i, int *index)
{
	int j;
	int c;

	j = 0;
	while (s1[j] != '\0')
	{
		c = 0;
		while (set[c] != '\0')
		{
			if (s1[*index] == set[c])
			{
				*index += 1;
				break ;
			}
			if (s1[i] == set[c])
			{
				i--;
				break ;
			}
			c++;
		}
		j++;
	}
	return (i - *index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		length;
	int		j;
	int		index;

	index = 0;
	if (s1 == NULL)
		return (NULL);
	j = ft_strlen(s1);
	j--;
	length = trim_checker(s1, set, j, &index);
	p = (char*)malloc((length + 2) * sizeof(char));
	if (p == NULL)
		return (NULL);
	j = 0;
	while (j <= length)
	{
		p[j] = (char)s1[index];
		j++;
		index++;
	}
	p[j] = '\0';
	return (p);
}
