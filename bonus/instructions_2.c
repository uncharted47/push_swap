/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:09:32 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 18:39:34 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_stack **stack_A, t_stack **stack_B)
{
	ra(stack_A);
	ra(stack_B);
}

void	pb(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*head;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	head = (*stack_A)->next;
	ft_lstadd_front(stack_B, *stack_A);
	*stack_A = head;
}

void	pa(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*head;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	head = (*stack_B)->next;
	ft_lstadd_front(stack_A, *stack_B);
	*stack_B = head;
}

void	rra(t_stack **stack_A)
{
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	head = *stack_A;
	back = *stack_A;
	front = *stack_A;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*stack_A = front;
}

void	rrb(t_stack **stack_B)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	rra(stack_B);
}
