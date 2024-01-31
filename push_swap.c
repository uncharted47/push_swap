/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 20:33:13 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/31 02:02:01 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_exit("Error: argument with just spaces");
	}

}
	int *bubbleSort(int *arr, int n);

	int	*ft_fromstacktoarr(t_stack *stack_A);
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	**tmp;
	t_stack	**tmp1;

	a = NULL;
	b = NULL;
	tmp = &a;
	tmp1 = &b;
	if (argc < 2)
		return (ft_exit("Allocation failed\n"), 0);
	a = parse(a, &argv[1]);
	if (ft_sorted(a))
		return (ft_lstclear(tmp),ft_exit("Allocation failed\n"), 0);
	if (!a)
		return (ft_exit("Allocation failed\n"), 0);
	if (ft_lstsize(a) == 3)
		ft_sortthree(tmp);
	else if (ft_lstsize(a) < 6)
		ft_sortfive(tmp, tmp1);
	else
	{
		ft_pushnonlistob(tmp, tmp1);
		ft_9lebche9leb(tmp, tmp1);
	}
	ft_lstclear(tmp);
	return (0);
}
