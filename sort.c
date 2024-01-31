/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:29 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 02:16:58 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setrest(t_stack *stack)
{
	if (stack->posa >= 0)
		stack->ra = abs(stack->posa);
	else if (stack->posa < 0)
		stack->rra = abs(stack->posa);
	if (stack->posb >= 0)
		stack->rb = abs(stack->posb);
	else if (stack->posb < 0)
		stack->rrb = abs(stack->posb);
}

t_stack	*ft_find_the_cheapest(t_stack *stack_B)
{
	t_stack	*cheapestnum;
	int		cheapestabs;

	if (!stack_B)
		return (NULL);
	cheapestnum = NULL;
	cheapestabs = INT_MAX;
	while (stack_B)
	{
		if (((ft_check(stack_B)) < cheapestabs))
		{
			cheapestnum = stack_B;
			cheapestabs = (ft_check(stack_B));
		}
		stack_B = stack_B->next;
	}
	return (cheapestnum);
}

void	ft_setmoves(t_stack *stack_B)
{
	if (((stack_B->posa * stack_B->posb) > 0) && ((stack_B->posa) > 0)
		&& (stack_B->posb > 0))
		setrr(stack_B);
	else if (((stack_B->posa * stack_B->posb) > 0) && (stack_B->posa < 0)
		&& (stack_B->posb < 0))
		setrrr(stack_B);
	else
		setrest(stack_B);
}

void	ft_finalsort(t_stack **stack_A)
{
	t_stack	*small;

	small = findthesmallest(*stack_A);
	if (small->above_mediun)
	{
		while (*stack_A != small)
			ra(stack_A, 1);
	}
	else
	{
		while (*stack_A != small)
			rra(stack_A, 1);
	}
}

void	ft_9lebche9leb(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*head;

	while (*stack_B)
	{
		ft_setpositions(stack_A, stack_B);
		head = ft_find_the_cheapest(*stack_B);
		if (!head)
			return ;
		while ((head->rr > 0 && head->rr--))
			rr(stack_A, stack_B);
		while ((head->rrr > 0) && head->rrr--)
			rrr(stack_A, stack_B);
		while ((head->rb > 0) && head->rb--)
			rb(stack_B, 1);
		while ((head->ra > 0) && head->ra--)
			ra(stack_A, 1);
		while ((head->rra > 0) && head->rra--)
			rra(stack_A, 1);
		while ((head->rrb > 0) && head->rrb--)
			rrb(stack_B, 1);
		if (!ft_check(head))
			pa(stack_A, stack_B, 1);
	}
	ft_finalsort(stack_A);
}
