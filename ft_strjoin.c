/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:44:15 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 14:47:52 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_charjoin_r(char *s1, char c)
{
	char	*res;
	size_t	i;

	if (s1 == NULL)
		s1 = ft_strdup("");
	i = ft_strlen(s1);
	if ((res = (char *)malloc(i + 2)) == NULL)
		return (ft_strdup(""));
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = c;
	res[++i] = '\0';
	free(s1);
	return (res);
}

char	*ft_charjoin_l(char c, char *s1)
{
	char	*res;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ft_strdup("");
	i = ft_strlen(s1);
	j = i + 1;
	if ((res = (char *)malloc(i + 2)) == NULL)
		return (ft_strdup(""));
	while (i >= 0)
	{
		res[j] = s1[i];
		i--;
		j--;
	}
	res[j] = c;
	free(s1);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL)
		return ((char *)s2);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if ((p = (char*)malloc((j + i + 1) * sizeof(char))) == NULL)
		return (ft_strdup(""));
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
	free(s1);
	free(s2);
	return (p);
}
