/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:21:10 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 21:25:01 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	if (!ft_morethantwo(*stack_A) && !ft_morethantwo(*stack_B))
		return ;
	rra(stack_A, 0);
	rra(stack_B, 0);
	write(1, "rrr\n", 4);
}

void	movethesmallest(t_stack **stack_A)
{
	t_stack	*small;

	small = findthesmallest(*stack_A);
	while (*stack_A != small)
	{
		if ((*stack_A)->above_mediun)
			ra(stack_A, 1);
		else
			rra(stack_A, 1);
	}
}

void	ft_sortthree(t_stack **stack_A)
{
	t_stack	*head;

	head = *stack_A;
	if (ft_sorted(*stack_A))
		return ;
	if (head->nb > head->next->nb && (head->nb < head->next->next->nb))
		sa(stack_A, 1);
	else if (head->nb > head->next->nb && (head->nb > head->next->next->nb)
		&& head->next->nb > head->next->next->nb)
	{
		sa(stack_A, 1);
		rra(stack_A, 1);
	}
	else if (head->nb > head->next->nb && (head->nb > head->next->next->nb)
		&& head->next->nb < head->next->next->nb)
		ra(stack_A, 1);
	else if (head->nb < head->next->nb && (head->nb < head->next->next->nb))
	{
		sa(stack_A, 1);
		ra(stack_A, 1);
	}
	else if (head->nb < head->next->nb && (head->nb > head->next->next->nb)
		&& head->next->nb > head->next->next->nb)
		rra(stack_A, 1);
}

void	ft_sortfive(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*nb;

	while (ft_lstsize(*stack_A) > 3)
	{
		ft_lstindex(*stack_A);
		nb = findthesmallest(*stack_A);
		if ((*stack_A)->nb == nb->nb)
			pb(stack_A, stack_B, 1);
		else if (nb->above_mediun)
			ra(stack_A, 1);
		else
			rra(stack_A, 1);
	}
	ft_sortthree(stack_A);
	while (ft_lstsize(*stack_B))
		pa(stack_A, stack_B, 1);
}

int	ft_morethantwo(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i >= 2)
			return (i);
		i++;
		lst = lst->next;
	}
	return (i);
}
