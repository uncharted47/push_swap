/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:15:16 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/28 16:22:05 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setrotations(t_stack *stack)
{
	if (!stack)
		return ;
	stack->ra = 0;
	stack->rra = 0;
	stack->rb = 0;
	stack->rrb = 0;
	stack->rrr = 0;
	stack->rr = 0;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (!(*lst))
	{
		ft_setrotations(new);
		(*lst) = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		ft_setrotations(new);
	}
}
