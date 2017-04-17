/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:08:47 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 20:08:49 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bnrdeci(char *bnr)
{
	int i;
	int deci;

	i = -1;
	deci = 0;
	while (bnr[++i])
		if (ft_isdigit(bnr[i]))
			deci = deci * 2 + (bnr[i] - 48);
	return (deci);
}

char	*ft_utoa_base(size_t n, size_t base)
{
	char	*s;
	char	*tmp;
	size_t	i;
	size_t	nb;
	size_t	len;

	i = 0;
	len = 0;
	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (nb >= 1 && ++len)
		nb = nb / base;
	s = ft_strnew(len);
	while (i < len)
	{
		s[i] = n % base + 48;
		if (!ft_isdigit(s[i]))
			s[i] = s[i] + 39;
		n = n / base;
		++i;
	}
	tmp = ft_strrev(s);
	ft_strdel(&s);
	return (tmp);
}

char	*ft_chosemask(char *bnr)
{
	char	*mask;
	int		len;

	mask = NULL;
	len = ft_strlen_p(bnr);
	if (len > 7 && len < 12)
		mask = ft_strdup("110xxxxx10xxxxxx");
	else if (len > 11 && len < 17)
		mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	else if (len > 16 && len < 22)
		mask = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx");
	else
		mask = ft_strdup(bnr);
	return (mask);
}

char	*ft_apmask(char *mask, char *bnr)
{
	int	i;
	int	j;

	i = ft_strlen_p(mask) - 1;
	j = ft_strlen_p(bnr) - 1;
	while (i >= 0)
	{
		if (!ft_isdigit(mask[i]) && i >= 0)
		{
			if (j >= 0)
				mask[i] = bnr[j--];
			else
				mask[i] = 48;
			--i;
		}
		else
			--i;
	}
	return (mask);
}

char	*ft_getwchar(int c)
{
	t_uni	u;
	char	*unicode;
	int		i;
	int		start;

	i = -1;
	start = 0;
	u.bnr = ft_utoa_base(c, 2);
	u.mask = ft_chosemask(u.bnr);
	u.mask = ft_apmask(u.mask, u.bnr);
	unicode = ft_strnew(4);
	while (++i < 4)
	{
		u.tmp = ft_strsub(u.mask, start, 8);
		unicode[i] = ft_bnrdeci(u.tmp);
		ft_strdel(&u.tmp);
		start += 8;
	}
	ft_strdel(&u.bnr);
	ft_strdel(&u.mask);
	return (unicode);
}
