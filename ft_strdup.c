/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:09:56 by bamghoug          #+#    #+#             */
/*   Updated: 2019/12/18 14:42:57 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*res;
	int		i;

	i = ft_strlen(s1);
	if ((p = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	res = ft_memcpy(p, s1, (i + 1));
	return (res);
}
