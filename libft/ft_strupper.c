/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:17 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:32:20 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str)
{
	char	*new;
	int		i;

	i = ft_strlen_p(str);
	new = ft_strnew(i);
	i = -1;
	while (str[++i])
		new[i] = (char)ft_toupper(str[i]);
	ft_strdel(&str);
	return (new);
}
