/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:47:03 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/27 17:12:54 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = (*lst);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}
