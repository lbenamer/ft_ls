/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:31:23 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:31:24 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_fixops(void *arg, t_flags f, t_ops sv, t_mod mod)
{
	char *argst;

	argst = NULL;
	argst = ft_conv(sv, arg, mod);
	if (ft_strchr("diD", sv.conv))
		argst = ft_fixops_d(argst, f, sv, arg);
	else if (ft_strchr("uUOo", sv.conv))
		argst = ft_fixops_oct(argst, f, sv);
	else if (ft_strchr("xX", sv.conv))
		argst = ft_fixops_x(argst, f, sv);
	else if (ft_strchr("SCsc%", sv.conv))
		argst = ft_fixops_s(argst, f, sv);
	return (argst);
}

t_ops		ft_disp_ops(char *ops)
{
	t_ops	sv;

	sv.flags = NULL;
	sv.modif = NULL;
	sv.flags = ft_sv_flags(ops);
	sv.chp = ft_sv_chp(ops);
	sv.precis = ft_sv_precis(ops);
	sv.modif = ft_sv_modif(ops);
	sv.conv = ft_sv_conv(ops);
	return (sv);
}

t_flags		ft_check_flags(char *flags)
{
	t_flags	fg;

	fg.plus = 0;
	fg.less = 0;
	fg.hstg = 0;
	fg.space = 0;
	fg.zero = 0;
	if (!flags)
		return (fg);
	if (ft_strchr(flags, '+'))
		fg.plus = 1;
	if (ft_strchr(flags, '-'))
		fg.less = 1;
	if (ft_strchr(flags, '#'))
		fg.hstg = 1;
	if (ft_strchr(flags, ' '))
		fg.space = 1;
	if (ft_strchr(flags, '0'))
		fg.zero = 1;
	ft_strdel(&flags);
	return (fg);
}

t_mod		ft_check_modif(char *modif)
{
	t_mod	mod;

	mod.h = 0;
	mod.hh = 0;
	mod.l = 0;
	mod.ll = 0;
	mod.j = 0;
	mod.z = 0;
	if (!ft_strcmp(modif, "h"))
		mod.h = 1;
	if (!ft_strcmp(modif, "hh"))
		mod.hh = 1;
	if (!ft_strcmp(modif, "l"))
		mod.l = 1;
	if (!ft_strcmp(modif, "ll"))
		mod.ll = 1;
	if (!ft_strcmp(modif, "z"))
		mod.z = 1;
	if (!ft_strcmp(modif, "j"))
		mod.j = 1;
	ft_strdel(&modif);
	return (mod);
}
