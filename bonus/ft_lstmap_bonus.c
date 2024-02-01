/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:12:21 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/01 20:59:46 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(void *))
{
	t_stack	*new;
	t_stack	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->nb));
		if (!new)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new);
		lst = lst->next;
	}
	return (new_list);
}
