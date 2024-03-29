/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:21:10 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 22:53:13 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	rra(stack_A);
	rra(stack_B);
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

int	ft_sorted(t_stack *a)
{
	while (a)
	{
		if (a->next && a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}
