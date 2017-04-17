/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:17:48 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:17:55 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sv_modif(char *ops)
{
	int		i;
	int		j;
	char	*modif;

	modif = ft_strnew(2);
	i = ft_strlen_p(ops) - 1;
	j = 0;
	while (ft_ismodif(ops[--i]) && ops[i])
		modif[j++] = ops[i];
	return (modif);
}

char	*ft_sv_ops(char *fmt)
{
	int		i;
	char	*ops;

	i = 0;
	ops = NULL;
	if (!fmt)
		return (NULL);
	while (!ft_isconv(fmt[i]) && fmt[i])
		++i;
	if (!ft_isconv(fmt[i]))
		return (NULL);
	ops = ft_strsub(fmt, 0, i + 1);
	return (ops);
}

char	ft_sv_conv(char *ops)
{
	int	i;

	i = ft_strlen_p(ops) - 1;
	return (ops[i]);
}

int		ft_sv_chp(char *ops)
{
	int		i;
	int		st;
	int		champs;
	char	*svd;

	i = 0;
	champs = 0;
	svd = NULL;
	while (ft_isflag(ops[i]) && ops[i])
		++i;
	st = i;
	while (ft_isdigit(ops[i]) && ops[i])
		++i;
	if (i <= 0)
		return (0);
	if (!(svd = ft_strsub(ops, st, i - st)))
		return (0);
	champs = ft_atoi(svd);
	ft_strdel(&svd);
	return (champs);
}

int		ft_sv_precis(char *ops)
{
	int		i;
	char	*precis;
	int		pr;
	int		st;
	int		len;

	i = 0;
	len = 0;
	while (ft_isflag(ops[i]) || ft_isdigit(ops[i]))
		++i;
	if (ops[i] != '.')
		return (0);
	else
		st = ++i;
	while (ft_isdigit(ops[i++]))
		++len;
	precis = ft_strsub(ops, st, len);
	if (ft_atoi(precis) == 0 || precis == 0)
		return (-1);
	pr = ft_atoi(precis);
	ft_strdel(&precis);
	return (pr);
}
