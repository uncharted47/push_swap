/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:06:17 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 20:59:49 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->nb);
		lst = lst->next;
	}
}
