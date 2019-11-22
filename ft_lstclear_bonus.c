/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 08:37:46 by bamghoug          #+#    #+#             */
/*   Updated: 2019/11/03 22:46:13 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*follow;

	while (lst != NULL)
	{
		follow = (*lst)->next;
		(*del)((*lst)->content);
		free((*lst));
		(*lst) = follow;
	}
}
