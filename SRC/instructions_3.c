/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:21:10 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 02:12:41 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	rra(stack_A, 0);
	rra(stack_B, 0);
	write(1,"rrr\n",4);
}

void	ft_sortthree(t_stack **stack_A)
{
	t_stack	*head;

	head = *stack_A;
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
	t_stack		*nb;
	t_stack	*tmp;

	tmp = *stack_A;

	while (ft_lstsize(*stack_A) > 3)
	{
		ft_lstindex(*stack_A);
		nb = findthesmallest(*stack_A);
		if ((*stack_A)->nb == nb->nb)
			pb(stack_A, stack_B, 1);
		else if(nb->above_mediun)
			ra(stack_A, 1);
		else
			rra(stack_A, 1);
	}
	ft_sortthree(stack_A);
	while (ft_lstsize(*stack_B))
		pa(stack_A,stack_B,1);
}

int	ft_morethantwo(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if(i >= 2)
			return(i);
		i++;
		lst = lst->next;
	}
	return (i);
}

