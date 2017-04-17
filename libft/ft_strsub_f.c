/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:30:55 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:30:56 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_f(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = ft_strnew(len);
	i = -1;
	while (++i < len && s[i])
		sub[i] = s[i + start];
	sub[i] = '\0';
	ft_strdel(&s);
	return (sub);
}
