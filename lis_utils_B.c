/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:41:29 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/30 23:08:01 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_save(int length, int flag)
{
	static int	len;

	if (flag)
	{
		len = length;
		return (len);
	}
	else
		return (len);
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
