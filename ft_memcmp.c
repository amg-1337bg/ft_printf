/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:24:09 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 10:56:52 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss;
	unsigned char	*sa;
	size_t			i;

	i = 0;
	ss = (unsigned char*)s1;
	sa = (unsigned char*)s2;
	while (i < n && *ss == *sa)
	{
		i++;
		ss++;
		sa++;
	}
	if (i == n)
		return (0);
	return (*ss - *sa);
}
