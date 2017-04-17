/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:38:13 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 15:58:19 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;
	int		i;
	int		cmp;

	i = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			cmp = ft_strncmp((big + i), little, len);
			if (cmp == 0)
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
