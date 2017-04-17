/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:12:35 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 16:12:37 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	start;
	char	*trim;

	if (!s)
		return (NULL);
	start = 0;
	while ((s[start] == ' ' || s[start] == '\t' || s[start] == '\n') && s)
		start++;
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i > 0)
		--i;
	if (i < start)
		return (ft_strdup(s + start));
	i = i - start + 1;
	trim = ft_strsub(s, start, i);
	return (trim);
}
