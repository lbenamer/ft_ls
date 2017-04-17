/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 00:06:59 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 00:07:00 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_oct(size_t n)
{
	char	*s;
	char	*tmp;
	size_t	i;
	size_t	nb;
	size_t	len;

	nb = n;
	i = 0;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (nb >= 1 && ++len)
		nb = nb / 8;
	s = ft_strnew(len);
	while (i < len)
	{
		s[i] = n % 8 + 48;
		n = n / 8;
		++i;
	}
	tmp = ft_strrev(s);
	ft_strdel(&s);
	return (tmp);
}

char	*ft_utoa_hexmin(size_t n)
{
	char	*s;
	char	*tmp;
	size_t	i;

	i = 0;
	s = ft_strnew(8);
	if (n == 0 || n == 4294967296)
		return (ft_strdup("0"));
	while (i < 8 && n)
	{
		s[i] = n % 16 + 48;
		if (!ft_isdigit(s[i]))
			s[i] = s[i] + 39;
		n = n / 16;
		++i;
	}
	tmp = ft_strrev(s);
	ft_strdel(&s);
	return (tmp);
}

char	*ft_utoa_x(size_t n)
{
	char	*s;
	size_t	nb;
	size_t	len;
	char	*tmp;
	size_t	i;

	i = 0;
	nb = n;
	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (nb >= 1 && ++len)
		nb = nb / 16;
	s = ft_strnew(len);
	while (i < len)
	{
		s[i] = n % 16 + 48;
		if (!ft_isdigit(s[i]))
			s[i] = s[i] + 39;
		n = n / 16;
		++i;
	}
	tmp = ft_strrev(s);
	ft_strdel(&s);
	return (tmp);
}
