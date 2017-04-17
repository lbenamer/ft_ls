/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:10:16 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 16:10:18 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *tab, size_t size)
{
	int		i;
	char	*temp;

	i = 0;
	while (tab[i])
		i++;
	temp = malloc(sizeof(char) * (size + i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		temp[i] = tab[i];
		i++;
	}
	free(tab);
	return (temp);
}
