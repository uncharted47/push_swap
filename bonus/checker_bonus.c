/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 06:53:14 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 18:37:26 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack **stack_A;
	t_stack **stack_B;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	stack_A = &a;
	stack_B = &b;
	line = get_next_line(0);
	if(argc < 3)
		ft_exit("KO\n");
	while (line)
	{
		a = parse(a, &argv[1]);
		if (!a)
			return (0);
		if (ft_strncmp(line, "ra\n", 3))
			ra(stack_A, 1);
		else if (ft_strncmp(line, "rb\n", 3))
			rb(stack_A, 1);
		else if (ft_strncmp(line, "rr\n", 3))
			rr(stack_A, stack_B);
		else if (ft_strncmp(line, "rra\n", 3))
			rra(stack_A, 1);
		else if (ft_strncmp(line, "rrb\n", 3))
			rrb(stack_A, 1);
		else if (ft_strncmp(line, "rrr\n", 3))
			rrr(stack_A,stack_B);
		else if (ft_strncmp(line, "pa\n", 3))
			pa(stack_A,stack_B,1);
		else if (ft_strncmp(line, "pb\n", 3))
			pb(stack_A,stack_B,1);
		free(line);
		line = get_next_line(0);
	}
	if (ft_sorted(a) && *stack_B == NULL)
		write(1,"OK\n",3);
	else
		write(1,"KO\n",3);
	return (0);
}
