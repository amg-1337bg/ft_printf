/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:04:05 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 19:58:48 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss;
	unsigned char	*sa;
	size_t			i;

	i = 0;
	ss = (unsigned char*)s1;
	sa = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (ss[i] == sa[i] && ss[i] != '\0' && sa[i] != '\0' && i < n)
		i++;
	if (i == n)
		return (0);
	return (ss[i] - sa[i]);
}
