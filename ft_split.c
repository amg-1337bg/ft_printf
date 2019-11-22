/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:51:28 by bamghoug          #+#    #+#             */
/*   Updated: 2019/10/29 10:24:46 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		hm_word(char const *s, char c)
{
	int i;
	int j;
	int checker;

	i = 0;
	j = 0;
	checker = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			checker++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	if (checker == 0 && j == 0)
		return (-1);
	return (j);
}

char	*hm_inword(char const *s, int word_len, int j)
{
	int				i;
	int				t;
	unsigned char	*pt;

	i = 0;
	if (s == NULL)
		return (NULL);
	pt = (unsigned char*)malloc((word_len + 1) * sizeof(char));
	if (pt == NULL)
		return (NULL);
	t = j - word_len;
	while (i < word_len)
	{
		pt[i] = (char)s[t];
		i++;
		t++;
	}
	pt[i] = '\0';
	return ((char*)pt);
}

void	work(char const *s, unsigned char **p, char c, int i)
{
	int word_len;
	int x;
	int j;

	x = -1;
	j = 0;
	while ((++x) <= i)
	{
		while (s[j] != '\0')
		{
			word_len = 0;
			while (s[j] != c && s[j] != '\0')
			{
				word_len++;
				j++;
			}
			if (word_len == 0)
				j++;
			else
				break ;
		}
		p[x] = (unsigned char*)hm_inword(s, word_len, j);
		j++;
	}
	p[x] = NULL;
}

char	**ft_split(char const *s, char c)
{
	unsigned char	**p;
	char			*trim;
	int				i;

	if (s == NULL)
		return (NULL);
	trim = ft_strtrim(s, &c);
	i = hm_word(trim, c);
	p = (unsigned char**)malloc((i + 2) * sizeof(char*));
	if (p == NULL)
		return (NULL);
	work(trim, p, c, i);
	return ((char **)p);
}
