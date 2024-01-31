/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_A.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:53:26 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 06:48:35 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_reset(t_stack *head)
{
	head->ra = 0;
	head->rb = 0;
	head->rr = 0;
	head->rra = 0;
	head->rrb = 0;
	head->rrr = 0;
}

t_stack	*findthelargest(t_stack *stackA)
{
	long	largest;
	t_stack	*larg;

	largest = LONG_MIN;
	while (stackA)
	{
		if (stackA->nb > largest)
		{
			largest = stackA->nb;
			larg = stackA;
		}
		stackA = stackA->next;
	}
	return (larg);
}

void	ft_setcost(t_stack *stackA, t_stack *stackB)
{
	int	sizea;
	int	sizeb;

	sizea = ft_lstsize(stackA);
	sizeb = ft_lstsize(stackB);
	while (stackB)
	{
		if (!stackB->above_mediun)
			stackB->posb -= sizeb;
		if ((stackB->posa > (sizea / 2)))
			stackB->posa = stackB->posa - (sizea);
		else if ((stackB->posa <= (sizea / 2)))
			stackB->posa = stackB->posa;
		ft_setmoves(stackB);
		stackB = stackB->next;
	}
}

int	ft_check(t_stack *stack)
{
	return (stack->ra + stack->rb + stack->rra + stack->rr + stack->rrr
		+ stack->rrb);
}
