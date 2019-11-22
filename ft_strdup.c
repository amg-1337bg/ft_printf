/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:09:56 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 11:28:02 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*res;
	int		i;

	i = ft_strlen(s1);
	p = (char*)malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	res = ft_memcpy(p, s1, (i + 1));
	return (res);
}
