/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyzouli <elyzouli@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:46:04 by elyzouli          #+#    #+#             */
/*   Updated: 2024/02/03 21:04:44 by elyzouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static size_t	ft_count_word(char const *str, char sep)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (str[i] == '\0')
		return (count);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (count);
}

char	**failsafe(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
	return (split);
}

static char	*ft_alloc(char *src, char sep)
{
	int		i;
	char	*split;
	int		sizeword;

	i = 0;
	sizeword = 0;
	while (src[sizeword] && !(sep == src[sizeword]))
		sizeword++;
	split = (char *)malloc(sizeof(char) * (sizeword + 1));
	if (!split)
		return (NULL);
	while (i < sizeword)
	{
		split[i] = src[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

static void	skipsepword(const char *str, char sep, int *i, int flag)
{
	if (flag)
	{
		while (str[*i] == sep)
			(*i)++;
	}
	else if (!flag)
	{
		while (str[*i] && str[*i] != sep)
			(*i)++;
	}
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	split = NULL;
	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_count_word(str, sep) + 1));
	if (!split)
		return (NULL);
	while (str && str[i])
	{
		skipsepword(str, sep, &i, 1);
		if (str[i])
		{
			split[k] = ft_alloc((char *)&str[i], sep);
			if (!split[k++])
				return (failsafe(split));
		}
		skipsepword(str, sep, &i, 0);
	}
	split[k] = NULL;
	return (split);
}
