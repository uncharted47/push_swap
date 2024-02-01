/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:21:10 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 18:35:48 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr(t_stack **stack_A, t_stack **stack_B)
{
	rra(stack_A, 0);
	rra(stack_B, 0);
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
