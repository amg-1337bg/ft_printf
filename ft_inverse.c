/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:08:57 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/22 11:09:00 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_inverse(char *str)
{
    char *res;
    size_t i;
    int j;

    j = 0;
    i = ft_strlen(str);
    res = (char*)malloc(i + 1);
    i--;
    while (i > 0)
    {
        res[j] = str[i];
        j++;
        i--;
    }
    res[j] = '\0';
    return(res);
}