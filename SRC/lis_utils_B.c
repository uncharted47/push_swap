/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:41:29 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/02 22:55:35 by elyzouli         ###   ########.fr       */
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubblesort(int *arr, int length)
{
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < length - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}

void	ft_pushtob_intialisation(t_stack **stack_A,
		int **arr, int **sorted)
{
	int	len;

	len = ft_lstsize(*stack_A);
	*arr = ft_lis(ft_fromstacktoarr(*stack_A), len);
	if (!*arr)
		ft_exit("Error\n");
	*sorted = ft_fromstacktoarr(*stack_A);
	if (!*sorted)
	{
		free(arr);
		ft_exit("Error\n");
	}
}

void	ft_free(t_lis *lis, int *arr)
{
	free(lis->length);
	free(lis->sub);
	free(arr);
	free(lis);
}
