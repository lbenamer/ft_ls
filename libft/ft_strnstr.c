/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:03:46 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 16:05:58 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		len;
	size_t		i;
	int			cmp;

	i = 0;
	if (ft_strlen(big) == 0)
		return (NULL);
	len = ft_strlen(little);
	if (len == 0)
		return ((char*)big);
	if (n == 0)
		return (NULL);
	while (i < n && big[i])
	{
		if (big[i] == little[0])
		{
			cmp = ft_strncmp((big + i), little, len);
			if (cmp == 0 && (ft_strlen(little) + i) <= n)
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
