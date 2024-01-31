/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:13:36 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/30 20:25:08 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstindex(t_stack *lst)
{
	int	i;
	int	size;
	int largest;

	largest = lst->nb;
	size = ft_lstsize(lst);
	i = 1;
	while (lst)
	{
		lst->index = i;
		if (i <= (size / 2))
			lst->above_mediun = TRUE;
		else
			lst->above_mediun = FALSE;
		if (lst->nb > largest)
			largest = lst->nb;
		lst = lst->next;
		i++;
	}
	return (largest);
}
