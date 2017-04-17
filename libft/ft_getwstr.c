/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:23:34 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:23:35 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getwstr(int *ws)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_getwchar(ws[0]);
	while (ws[++i])
	{
		tmp = ft_getwchar(ws[i]);
		str = ft_strjoinf(str, tmp, 1);
		if (tmp)
			ft_strdel(&tmp);
	}
	return (str);
}
