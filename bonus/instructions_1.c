/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:07:26 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 18:39:32 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_stack **stack_A)
{
	int	tmp;

	if (ft_morethantwo(*stack_A) < 2)
		return ;
	(*stack_A) = ft_lstfirst((*stack_A));
	tmp = (*stack_A)->nb;
	(*stack_A)->nb = (*stack_A)->next->nb;
	(*stack_A)->next->nb = tmp;
}

void	sb(t_stack **stack_B)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	sa(stack_B);
}

void	ss(t_stack **stack_A, t_stack **stack_B)
{
	if (ft_morethantwo(*stack_A) < 2 && ft_morethantwo(*stack_B) < 2)
		return ;
	sa(stack_A);
	sb(stack_B);
}

void	ra(t_stack **stack_A)
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
}

void	rb(t_stack **stack_B)
{
	if (ft_morethantwo(*stack_B) < 2)
		return ;
	ra(stack_B);
}
