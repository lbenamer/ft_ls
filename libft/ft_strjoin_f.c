/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:26:02 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 18:26:03 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char *s2, int f)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	str = ft_strnew(ft_strlen_p(s1) + ft_strlen_p(s2));
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	if (f == 1 && s1)
		ft_strdel(&s1);
	if (f == 2 && s2)
		ft_strdel(&s2);
	if (f == 3 && s2 && s1)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
