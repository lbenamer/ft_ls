/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 00:52:05 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 00:52:07 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conv_c(t_mod mod, void *arg)
{
	char	*argst;
	int		uni;
	char	c;

	if (mod.l)
	{
		uni = (int)arg;
		argst = ft_getwchar(uni);
	}
	else
	{
		c = (char)arg;
		argst = ft_strset(c, 1);
	}
	return (argst);
}

char	*ft_conv_pc(t_mod mod, void *arg)
{
	char *argst;

	argst = NULL;
	mod.l = 0;
	arg = 0;
	argst = ft_strset('%', 1);
	return (argst);
}

char	*ft_conv_d(t_mod mod, void *arg)
{
	char *argst;
	long nb;

	nb = (long)arg;
	if (mod.h)
		nb = (short)nb;
	else if (mod.hh)
		nb = (char)nb;
	else if (mod.l)
		nb = (unsigned int)nb;
	else if (mod.ll || mod.j)
		nb = (long int)nb;
	else if (mod.z)
		nb = (unsigned long int)nb;
	else
		nb = (int)nb;
	argst = ft_litoa(nb);
	return (argst);
}

char	*ft_conv(t_ops sv, void *arg, t_mod mod)
{
	char	*argst;
	char	*parse;
	char	*(*tpf_cvmod[8])(t_mod, void*);
	int		i;

	parse = "dsxuopc%";
	if (ft_strchr("DOUCS", sv.conv))
		mod.l = 1;
	if (sv.conv == 'i')
		sv.conv = 'd';
	tpf_cvmod[0] = &ft_conv_d;
	tpf_cvmod[1] = &ft_conv_s;
	tpf_cvmod[2] = &ft_conv_x;
	tpf_cvmod[3] = &ft_conv_u;
	tpf_cvmod[4] = &ft_conv_o;
	tpf_cvmod[5] = &ft_conv_p;
	tpf_cvmod[6] = &ft_conv_c;
	tpf_cvmod[7] = &ft_conv_pc;
	i = -1;
	while (parse[++i])
		if (sv.conv == parse[i] || ft_tolower(sv.conv) == parse[i])
			argst = (*tpf_cvmod[i])(mod, arg);
	return (argst);
}
