/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:40:08 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 02:38:22 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isinthesub(int number, int *arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (number == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_validlisstack(t_stack *a, int *arr)
{
	int	length;
	int	i;

	i = 0;
	length = ft_save(0, 0);
	if (!a)
		return (0);
	while (a)
	{
		if (!ft_isinthesub(a->nb, arr, length))
			return (1);
		a = a->next;
	}
	return (0);
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


void	ft_pushnonlistob(t_stack **stack_A, t_stack **stack_B)
{
	int	len;
	int	*arr;
	int	*sorted;
	int	i;

	i = ft_lstsize(*stack_A) / 2;
	len = ft_lstsize(*stack_A);
	arr = ft_lis(ft_fromstacktoarr(*stack_A), len);
	sorted = ft_fromstacktoarr(*stack_A);
	bubbleSort(sorted, len);
	len = ft_save(0, 0);
	while ((*stack_A && ft_validlisstack(*stack_A, arr))
		|| (!ft_sorted(*stack_A)))
	{
		if (ft_isinthesub((*stack_A)->nb, arr, len))
			ra(stack_A, 1);
		else if ((*stack_A)->nb > sorted[i])
			pb(stack_A, stack_B, 1);
		else
		{
			pb(stack_A, stack_B, 1);
			rb(stack_B, 1);
		}
	}
	free(sorted);
	free(arr);
}

int	*ft_fromstacktoarr(t_stack *stack_A)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * (ft_lstsize(stack_A)));
	i = 0;
	while (stack_A)
	{
		arr[i] = stack_A->nb;
		stack_A = stack_A->next;
		i++;
	}
	return (arr);
}
