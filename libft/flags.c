/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:23:59 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:24:04 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putprint(char *fmt, t_print p, int i, int *start)
{
	char	*format;
	char	*tmp;
	int		ret;

	format = NULL;
	tmp = NULL;
	ret = 0;
	if ((format = ft_strsub(fmt, *start, i - *start)) != NULL)
	{
		ft_putstr(format);
		ret = ft_strlen_p(format);
		ft_strdel(&format);
	}
	ft_putstr(p.argst);
	ret = ret + ft_strlen(p.argst);
	*start = i + ft_strlen_p(p.ops) + 1;
	if (!ft_strchr((fmt + *start), '%') && fmt[*start])
		if ((tmp = ft_strsub(fmt, *start, ft_strlen_p(fmt) - *start)) != NULL)
		{
			ft_putstr(tmp);
			ret = ret + ft_strlen_p(tmp);
			ft_strdel(&tmp);
		}
	ft_strdel(&p.argst);
	return (ret);
}

char	*ft_make_argst(char *ops, void *arg)
{
	t_ops	sv;
	t_flags	f;
	t_mod	mod;
	char	*argst;

	argst = NULL;
	sv = ft_disp_ops(ops);
	mod = ft_check_modif(sv.modif);
	f = ft_check_flags(sv.flags);
	argst = ft_fixops(arg, f, sv, mod);
	return (argst);
}
