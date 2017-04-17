/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:34:36 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:34:38 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinstr(char *str, int free, int nb, ...)
{
	int		i;
	char	*tmp;
	va_list ap;

	i = -1;
	va_start(ap, nb);
	while (++i < nb)
	{
		tmp = va_arg(ap, char*);
		str = ft_strjoinf(str, tmp, free);
	}
	va_end(ap);
	return (str);
}

char	*ft_strset(char c, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	str = ft_strnew(len);
	while (++i < len)
		str[i] = c;
	str[i] = '\0';
	return (str);
}
