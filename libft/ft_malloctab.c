/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloctab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:56:45 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 15:56:51 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_malloctab(size_t size, size_t len)
{
	int		**tab;
	size_t	i;

	if (!size || !len)
		return (NULL);
	if (!(tab = (int**)malloc(sizeof(int *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * len)))
			return (NULL);
		i++;
	}
	return (tab);
}
