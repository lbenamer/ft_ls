/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:58:33 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 16:58:35 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_tprint(t_print *p)
{
	p->i = -1;
	p->nl = 0;
	p->ret = 0;
	p->start = 0;
	p->ops = NULL;
	p->argst = NULL;
	p->arg = NULL;
}

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	t_print	p;

	ft_init_tprint(&p);
	va_start(ap, fmt);
	!ft_strchr(fmt, '%') ? p.ret = ft_putstr(fmt) : 0;
	while (fmt[++p.i])
	{
		if (fmt[p.i] == '%' && (ft_strchr(p.ops, '%')))
			ft_strdel(&p.ops);
		else if (fmt[p.i] == '%' && (!ft_strchr(p.ops, '%')))
		{
			p.ops ? ft_strdel(&p.ops) : 0;
			p.ops = ft_sv_ops(fmt + p.i + 1);
			!p.ops ? p.ret = ft_putstr(fmt + p.i + 1) : 0;
			!ft_strchr(p.ops, '%') && p.ops ? p.arg = va_arg(ap, void*) : 0;
			ft_strchr(p.ops, 'c') && !p.arg ? ++p.nl : 0;
			p.ops ? p.argst = ft_make_argst(p.ops, p.arg) : 0;
			p.ops ? p.ret = p.ret + ft_putprint(fmt, p, p.i, &p.start) : 0;
		}
	}
	va_end(ap);
	ft_strdel(&p.ops);
	return (p.ret + p.nl);
}
