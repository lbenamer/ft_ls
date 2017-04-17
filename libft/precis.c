/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:02:15 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 16:02:18 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsgd_precis(char *argst, int precis)
{
	int		len;
	char	*stpr;

	stpr = NULL;
	if (!ft_strcmp(argst, "0") && precis == -1)
	{
		ft_strdel(&argst);
		return (ft_strnew(0));
	}
	if ((int)ft_strlen_p(argst) >= precis)
		return (argst);
	else
	{
		len = precis - ft_strlen_p(argst);
		stpr = ft_strset('0', len);
		argst = ft_strjoinf(stpr, argst, 3);
	}
	return (argst);
}

char	*ft_sgd_precis(char *argst, int precis)
{
	int		len;
	char	*stpr;
	char	*neg;

	stpr = NULL;
	neg = NULL;
	if ((int)ft_strlen_p(argst) - 1 >= precis)
		return (argst);
	else
	{
		neg = ft_strdup("-");
		len = precis - ft_strlen_p(argst) + 1;
		stpr = ft_strset('0', len);
		argst = ft_strsub_f(argst, 1, ft_strlen_p(argst) - 1);
		argst = ft_joinstr(neg, 3, 2, stpr, argst);
		return (argst);
	}
}

char	*ft_s_precis(char *argst, int precis)
{
	if (precis == -1)
		precis = 0;
	if (precis < (int)ft_strlen_p(argst))
	{
		precis = ft_adjustprecis(precis, argst);
		argst = ft_strsub_f(argst, 0, precis);
	}
	return (argst);
}

int		ft_adjustprecis(int precis, char *argst)
{
	int		i;
	int		j;
	int		oct;
	char	*bnr;

	i = 0;
	j = -1;
	oct = 0;
	while (argst[i])
	{
		if (argst[i] < 0)
		{
			bnr = ft_utoa_base((unsigned char)argst[i], 2);
			while (bnr[++j] == '1')
				++oct;
			ft_strdel(&bnr);
			if (precis < i + oct)
			{
				precis = i + 1;
				break ;
			}
		}
		++i;
	}
	return (precis);
}
