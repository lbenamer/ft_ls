/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 00:32:35 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/31 00:32:37 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conv_s(t_mod mod, void *arg)
{
	char	*argst;
	char	*tmp;

	argst = NULL;
	tmp = (char*)arg;
	if (!tmp)
		argst = ft_strdup("(null)");
	else if (mod.l)
		argst = ft_getwstr((int*)arg);
	else
		argst = ft_strdup(tmp);
	return (argst);
}

char	*ft_conv_x(t_mod mod, void *arg)
{
	char *argst;

	argst = NULL;
	if (mod.ll || mod.l || mod.j)
		argst = ft_utoa_x((long)arg);
	else if (mod.h)
		argst = ft_utoa_hexmin((unsigned short)arg);
	else if (mod.hh)
		argst = ft_utoa_hexmin((unsigned char)arg);
	else
		argst = ft_utoa_hexmin((size_t)arg);
	return (argst);
}

char	*ft_conv_u(t_mod mod, void *arg)
{
	char *argst;

	argst = NULL;
	if (mod.l || mod.ll || mod.j)
		argst = ft_litoa((unsigned long)arg);
	else if (mod.h)
		argst = ft_litoa((unsigned short)arg);
	else if (mod.hh)
		argst = ft_litoa((unsigned char)arg);
	else
		argst = ft_litoa((unsigned int)arg);
	return (argst);
}

char	*ft_conv_o(t_mod mod, void *arg)
{
	char *argst;

	argst = NULL;
	if (mod.h)
		argst = ft_utoa_oct((unsigned short)arg);
	else if (mod.hh)
		argst = ft_utoa_oct((unsigned char)arg);
	else
		argst = ft_utoa_oct((unsigned int)arg);
	return (argst);
}

char	*ft_conv_p(t_mod mod, void *arg)
{
	char *argst;
	char *tmp;

	mod.l = 0;
	argst = NULL;
	tmp = ft_utoa_x((size_t)arg);
	argst = ft_strjoinf("0x", tmp, 2);
	return (argst);
}
