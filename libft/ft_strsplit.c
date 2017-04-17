/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:58:08 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 15:58:10 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnbsplit(const char *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
			--i;
		}
		i++;
	}
	return (j);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	start;
	char	**tab;
	size_t	n;

	n = 0;
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * ft_strnbsplit(s, c) + 1)) || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[n++] = ft_strsub(s, start, i - start)))
				return (NULL);
			--i;
		}
		i++;
	}
	tab[n] = 0;
	return (tab);
}
