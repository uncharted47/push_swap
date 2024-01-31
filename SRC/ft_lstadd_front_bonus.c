/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:59:12 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 01:20:33 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	if (!lst || !new)
		return ;
	head = *lst;
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *lst;
		new->prev = NULL;
		head->prev = new;
		*lst = new;
	}
}
