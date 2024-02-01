/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:59:12 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:13 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
