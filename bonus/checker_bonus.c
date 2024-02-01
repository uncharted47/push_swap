/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:53:14 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 23:04:00 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_checkspaces(char **argv)
{
	int	j;
	int	i;
	int	number;

	number = 0;
	i = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j][i] == '\t' || argv[j][i] == '\n' || argv[j][i] == ' '
			|| argv[j][i] == '\r' || argv[j][i] == '\v' || argv[j][i++] == '\f')
			number++;
		if (ft_strlen(argv[j++]) == number)
			ft_exit("Error\n");
	}
}

void	ft_clear(t_stack **stack_A, t_stack **stack_B)
{
	ft_lstclear(stack_A);
	ft_lstclear(stack_B);
	ft_exit("Error:\n");
}

void	ft_testmoves(char *line, t_stack **stack_A, t_stack **stack_B)
{
	if (ft_strncmp(line, "ra\n", 2))
		ra(stack_A);
	else if (ft_strncmp(line, "rb\n", 2))
		rb(stack_B);
	else if (ft_strncmp(line, "rr\n", 2))
		rr(stack_A, stack_B);
	else if (ft_strncmp(line, "rra\n", 3))
		rra(stack_A);
	else if (ft_strncmp(line, "rrb\n", 3))
		rrb(stack_B);
	else if (ft_strncmp(line, "rrr\n", 3))
		rrr(stack_A, stack_B);
	else if (ft_strncmp(line, "pa\n", 2))
		pa(stack_A, stack_B);
	else if (ft_strncmp(line, "pb\n", 2))
		pb(stack_A, stack_B);
	else if (ft_strncmp(line, "sa\n", 2))
		sa(stack_A);
	else if (ft_strncmp(line, "sb\n", 2))
		sb(stack_B);
	else if (ft_strncmp(line, "ss\n", 2))
		ss(stack_A, stack_B);
	else
		ft_clear(stack_A, stack_B);
}

void	ft_finalcheck(t_stack **stack_A, t_stack **stack_B)
{
	if (ft_sorted(*stack_A) && *stack_B == NULL)
	{
		ft_lstclear(stack_A);
		ft_lstclear(stack_B);
		write(1, "OK\n", 3);
	}
	else
	{
		ft_lstclear(stack_A);
		ft_lstclear(stack_B);
		write(1, "KO\n", 3);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	**stacka;
	t_stack	**stackb;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	stacka = &a;
	stackb = &b;
	ft_checkspaces(&argv[1]);
	a = parse(a, &argv[1]);
	if (!a)
		return (ft_exit("Error:\n"), 0);
	line = get_next_line(0);
	if (argc < 2)
		return (0);
	while (line)
	{
		ft_testmoves(line, stacka, stackb);
		free(line);
		line = get_next_line(0);
	}
	ft_finalcheck(stacka, stackb);
	return (0);
}
