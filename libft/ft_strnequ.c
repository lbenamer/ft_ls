/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:00:04 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 16:00:06 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int cmp;

	if (!s1 || !s2)
		return (0);
	cmp = ft_strncmp(s1, s2, n);
	if (cmp == 0)
		return (1);
	return (0);
}
