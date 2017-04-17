/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:30:35 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/29 06:31:36 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * ft_strlen_p(s1)
		+ ft_strlen_p(s2) + 1)))
		return (NULL);
	if (!s1)
	{
		new = ft_strcpy(new, s2);
		return (new);
	}
	if (!s2)
	{
		new = ft_strcpy(new, s1);
		return (new);
	}
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	ft_strdel(&s1);
	return (new);
}

char	*ft_strsub_free(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	sub = (char*)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[i + start];
	sub[i] = '\0';
	ft_strdel(&s);
	return (sub);
}

int		get_next_line(int fd, char **line)
{
	size_t		i;
	char		*buf;
	static char *s;

	i = -1;
	buf = ft_strnew(BUFF_SIZE);
	if ((read(fd, buf, BUFF_SIZE)) == -1 || fd < 0)
		return (-1);
	s ? s = ft_strjoin_free(s, buf) : 0;
	!s ? s = ft_strdup(buf) : 0;
	if (!ft_strlen(s))
		return (0);
	if (!ft_strchr(s, '\n') && ft_strlen(buf))
	{
		ft_strdel(&buf);
		return (get_next_line(fd, line));
	}
	while (s[++i] != '\n' && s[i])
		ft_strdel(&buf);
	line[0] = ft_strsub(s, 0, i);
	s[i] != '\n' ? s = ft_strnew(1) : 0;
	s[i] == '\n' ? s = ft_strsub_free(s, i + 1, ft_strlen(s) - i + 1) : 0;
	return (1);
}
