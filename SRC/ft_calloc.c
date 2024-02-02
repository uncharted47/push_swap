/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:53:11 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/15 14:56:45 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*mem;

	if (elementSize && elementCount >= SIZE_MAX / elementSize)
		return (NULL);
	mem = malloc(elementCount * elementSize);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (elementCount * elementSize));
	return (mem);
}
