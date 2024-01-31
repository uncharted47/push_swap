/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:07:26 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 06:48:14 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_A, int flag)
{
	int	tmp;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	(*stack_A) = ft_lstfirst((*stack_A));
	tmp = (*stack_A)->nb;
	(*stack_A)->nb = (*stack_A)->next->nb;
	(*stack_A)->next->nb = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_B, int flag)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	sa(stack_B, 0);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_A, t_stack **stack_B)
{
	if (ft_morethantwo(*stack_A) < 2 && ft_morethantwo(*stack_B) < 2)
		return ;
	sa(stack_A, 0);
	sb(stack_B, 0);
	write(1, "ss\n", 3);
}

void	ra(t_stack **stack_A, int flag)
{
	t_stack	*head;
	t_stack	*last;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	head = *stack_A;
	last = ft_lstlast(head);
	*stack_A = head->next;
	(*stack_A)->prev = NULL;
	last->next = head;
	head->prev = last;
	head->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_B, int flag)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	ra(stack_B, 0);
	if (flag)
		write(1, "rb\n", 3);
}
