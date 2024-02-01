/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:13:36 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:00 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_lstindex(t_stack *lst)
{
	int	i;
	int	size;
	int	largest;

	largest = lst->nb;
	size = ft_lstsize(lst);
	i = 1;
	while (lst)
	{
		lst->index = i;
		if (i <= (size / 2))
			lst->above_mediun = 1;
		else
			lst->above_mediun = 0;
		if (lst->nb > largest)
			largest = lst->nb;
		lst = lst->next;
		i++;
	}
	return (largest);
}
