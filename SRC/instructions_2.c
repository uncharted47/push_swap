/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:09:32 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 04:27:19 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_A, t_stack **stack_B)
{
	if (!ft_morethantwo(*stack_A) && !ft_morethantwo(*stack_B))
		return ;
	ra(stack_A, 0);
	ra(stack_B, 0);
	write(1, "rr\n", 3);
}

void	pb(t_stack **stack_A, t_stack **stack_B, int flag)
{
	t_stack	*head;

	if (!ft_morethantwo(*stack_A))
		return ;
	head = (*stack_A)->next;
	ft_lstadd_front(stack_B, *stack_A);
	*stack_A = head;
	if (flag)
		write(1, "pb\n", 3);
}

void	pa(t_stack **stack_A, t_stack **stack_B, int flag)
{
	t_stack	*head;

	if (!ft_morethantwo(*stack_B))
		return ;
	head = (*stack_B)->next;
	ft_lstadd_front(stack_A, *stack_B);
	*stack_B = head;
	if (flag)
		write(1, "pa\n", 3);
}

void	rra(t_stack **stack_A, int flag)
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
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_B, int flag)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	rra(stack_B, 0);
	if (flag)
		write(1, "rrb\n", 4);
}
