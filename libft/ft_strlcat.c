/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:00:47 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/21 19:16:31 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	n;

	i = 0;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (size > d)
	{
		n = size - d - 1;
		while (i < n && src[i])
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
		return (d + s);
	}
	return (size + s);
}
