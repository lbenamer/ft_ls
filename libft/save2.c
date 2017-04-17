/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:21:35 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:21:37 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sv_flags(char *ops)
{
	int		i;
	char	*flags;

	i = 0;
	while (ft_isflag(ops[i]))
		++i;
	flags = ft_strsub(ops, 0, i);
	return (flags);
}

int		ft_isflag(char c)
{
	if (!ft_strchr("+-# 0", c))
		return (0);
	else
		return (1);
}

int		ft_ismodif(char c)
{
	if (!ft_strchr("hljz", c))
		return (0);
	else
		return (1);
}

int		ft_isconv(int c)
{
	if (c == 0)
		return (0);
	if (!ft_strchr("sSpdDioOuUxXcC%", c))
		return (0);
	else
		return (1);
}
