/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_B.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:55:35 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 23:51:12 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findlargest(t_stack *stack_A)
{
	long	largest;

	largest = LONG_MIN;
	while (stack_A)
	{
		if (stack_A->nb > largest)
		{
			largest = stack_A->nb;
		}
		stack_A = stack_A->next;
	}
	return (largest);
}

void	ft_setpos(t_stack *currentb, t_stack *heada, t_stack *smallest,int largest)
{
	if (currentb->nb > largest)
	{
		currentb->posa = smallest->index -1;
		currentb->posb = currentb->index - 1;
	}
	 else if ((currentb->nb > heada->nb) && (heada->nb > currentb->lastnb))
	{
			currentb->lastnb = heada->nb;
			currentb->posa = heada->index;
			currentb->posb = currentb->index - 1;
	}
	else if (currentb->nb < smallest->nb)
	{
		currentb->posa = smallest->index - 1;
			currentb->posb = currentb->index -1;
	}

}

void	ft_setpositions(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*heada;
	t_stack	*currentb;
	int		largest;
	t_stack *smallest;

	currentb = *stack_B;
	smallest = findthesmallest(*stack_A);
	ft_reset(currentb);
	largest = ft_lstindex(*stack_A);
	ft_lstindex(*stack_B);
	while (currentb)
	{
		currentb->lastnb = LONG_MIN;
		heada = *stack_A;
		ft_reset(currentb);
		while (heada)
		{
			ft_setpos(currentb, heada, smallest,largest);
			heada = heada->next;
		}
		currentb = currentb->next;
	}
	ft_setcost(*stack_A, *stack_B);
}

void	setrrr(t_stack *stack)
{
	if (abs(stack->posa) > abs(stack->posb))
	{
		stack->rrr = abs(stack->posb);
		stack->rra = abs(abs(stack->posa) - abs(stack->posb));
	}
	else if (abs(stack->posa) < abs(stack->posb))
	{
		stack->rrr = abs(stack->posa);
		stack->rrb = abs(abs(stack->posb) - abs(stack->posa));
	}
	else
		stack->rrr = abs(stack->posa);
}

void	setrr(t_stack *stack)
{
	if (abs(stack->posa) > abs(stack->posb))
	{
		stack->rr = abs(stack->posb);
		stack->ra = abs(abs(stack->posa) - abs(stack->posb));
	}
	else if (abs(stack->posa) < abs(stack->posb))
	{
		stack->rr = abs(stack->posa);
		stack->rb = abs(abs(stack->posb) - abs(stack->posa));
	}
	else
		stack->rr = abs(stack->posa);
}
