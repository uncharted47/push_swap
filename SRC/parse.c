/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:37:05 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 03:16:10 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

int	ft_fillstack(t_stack **stack, char *str)
{
	t_stack		*a;
	long long	numb;

	numb = ft_atoi(str);
	if (numb > INT_MAX || !ft_checkdup(*stack, numb) || checkvalidnumber(str))
	{
		ft_lstclear(stack);
		ft_exit("Error:\n");
	}
	a = ft_lstnew(numb);
	if (!a)
	{
		ft_lstclear(stack);
		ft_exit("Error\n");
	}
	ft_lstadd_back(stack, a);
	return (1);
}

int	ft_checkdup(t_stack *stack, int number)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->nb == number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	checkvalidnumber(char *number)
{
	int	signs;
	int	i;

	i = 0;
	signs = 0;
	while (number[i])
	{
		if ((number[i] == '+' || number[i] == '-') && !signs && !i)
		{
			i++;
			signs++;
			continue ;
		}
		if (!ft_isdigit(number[i]))
			return (1);
		i++;
	}
	if (signs > 1)
		return (1);
	return (0);
}

t_stack	*parse(t_stack *stack_A, char **str)
{
	char	**numbers;
	int		i;
	int		j;

	j = 0;
	i = 0;
	stack_A = NULL;
	while (str[j])
	{
		numbers = ft_split(str[j++], ' ');
		while (numbers[i])
		{
			ft_fillstack(&stack_A, numbers[i]);
			free(numbers[i++]);
		}
		free(numbers);
		i = 0;
	}
	return (stack_A);
}
