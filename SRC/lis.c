/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:51:47 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/02 22:38:01 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*findthesmallest(t_stack *stack_A)
{
	long	smallest;
	t_stack	*small;

	smallest = LONG_MAX;
	while (stack_A)
	{
		if (stack_A->nb < smallest)
		{
			smallest = stack_A->nb;
			small = stack_A;
		}
		stack_A = stack_A->next;
	}
	return (small);
}

void	ft_initialize(t_lis **lis, int len)
{
	(*lis) = malloc(sizeof(t_lis) * 2);
	if (!*lis)
		return ;
	(*lis)->length = (int *)calloc(len, sizeof(int));
	if (!(*lis)->length)
	{
		free(*lis);
		*lis = NULL;
		ft_exit("Error\n");
	}
	(*lis)->sub = (int *)calloc(len, sizeof(int));
	if (!(*lis)->sub)
	{
		free(*lis);
		free((*lis)->length);
		*lis = NULL;
		ft_exit("Error\n");
	}
	(*lis)->i = 0;
	while ((*lis)->i < len)
	{
		(*lis)->length[(*lis)->i] = 1;
		(*lis)->sub[(*lis)->i] = -1;
		(*lis)->i++;
	}
}

t_lis	*ft_lengthsub(int len, int *arr)
{
	t_lis	*lis;

	ft_initialize(&lis, len);
	if (!lis)
		return (NULL);
	lis->i = 1;
	while (lis->i < (len))
	{
		lis->j = 0;
		while (lis->j < lis->i)
		{
			if (arr[lis->j] < arr[lis->i] && (lis->length[lis->j]
					+ 1 > lis->length[lis->i]))
			{
				lis->length[lis->i] = lis->length[lis->j] + 1;
				lis->sub[lis->i] = lis->j;
			}
			lis->j++;
		}
		lis->i++;
	}
	return (lis);
}

int	*ft_getsubseq(int lengthmax, t_lis *lis, int *arr, int *subseq)
{
	int	i;

	if (!subseq)
		return (NULL);
	lengthmax = ft_save(lengthmax, 1);
	i = lengthmax - 1;
	while (lis->sub[lis->j] != -1)
	{
		subseq[i] = arr[lis->j];
		lis->j = lis->sub[lis->j];
		i--;
	}
	subseq[i] = arr[lis->j];
	return (subseq);
}

int	*ft_lis(int *arr, int len)
{
	int		*subseq;
	t_lis	*lis;
	int		lengthmax;

	lis = ft_lengthsub(len, arr);
	if (!lis)
		return (NULL);
	lis->i = len - 1;
	lengthmax = lis->length[0];
	while (lis->i >= 0)
	{
		if (lis->length[lis->i] > lengthmax)
		{
			lengthmax = lis->length[lis->i];
			lis->j = lis->i;
		}
		lis->i--;
	}
	subseq = ft_getsubseq(lengthmax, lis, arr, (int *)malloc(sizeof(int)
				* (lengthmax)));
	if (!subseq)
		return (ft_free(lis, arr), NULL);
	return (ft_free(lis, arr), subseq);
}
