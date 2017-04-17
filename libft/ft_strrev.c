/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:30:17 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:30:18 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	char	*rev;

	j = 0;
	i = ft_strlen(str);
	rev = ft_strnew(i);
	while (i)
		rev[j++] = str[--i];
	return (rev);
}
