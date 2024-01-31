/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:37:05 by elyzouli          #+#    #+#             */
/*   Updated: 2024/01/12 06:58:29 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*skipwhitespaces(char *n, int *sign)
{
	char	*number;

	number = (char *)n;
	while (*number == '\t' || *number == '\n' || *number == ' '
		|| *number == '\r' || *number == '\v' || *number == '\f')
		number++;
	if (*number == '-' || *number == '+')
	{
		if (!*(number + 1))
			return ("2147483649");
		if (*number == '-')
			*sign = -1;
		number++;
	}
	return ((char *)number);
}

long long	ft_atoi(char *num)
{
	int					sign;
	unsigned long long	n;
	int					i;

	n = 0;
	sign = 1;
	i = 0;
	num = skipwhitespaces(num, &sign);
	while ((num[i] >= '0' && num[i] <= '9'))
	{
		n = n * 10 + (num[i++] - '0');
		if (n > INT_MAX && sign == 0)
			return ((long long)INT_MAX + 8);
		if (n > INT_MAX && sign == 1)
			return ((long long)INT_MAX + 9);
	}
	return (n * sign);
}
