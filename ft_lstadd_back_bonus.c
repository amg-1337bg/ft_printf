/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 08:35:55 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 22:48:35 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst)
	{
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
	}
	else
		(*alst) = new;
}
