/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:34:31 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:34:33 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fixops_oct(char *argst, t_flags fg, t_ops sv)
{
	if (sv.precis)
		argst = ft_unsgd_precis(argst, sv.precis);
	argst = ft_oct_fgchp(argst, fg, sv.chp, sv.precis);
	return (argst);
}

char	*ft_fixops_d(char *argst, t_flags fg, t_ops sv, void *arg)
{
	if ((int)arg >= 0)
	{
		if (sv.precis)
			argst = ft_unsgd_precis(argst, sv.precis);
		argst = ft_unsgd_fgchp(argst, fg, sv.chp, sv.precis);
	}
	else
	{
		if (sv.precis)
			argst = ft_sgd_precis(argst, sv.precis);
		argst = ft_sgd_fgchp(argst, fg, sv.chp, sv.precis);
	}
	return (argst);
}

char	*ft_fixops_x(char *argst, t_flags fg, t_ops sv)
{
	if (sv.precis)
		argst = ft_unsgd_precis(argst, sv.precis);
	argst = ft_x_fgchp(argst, fg, sv.chp, sv.precis);
	if (sv.conv == 'X')
		argst = ft_strupper(argst);
	return (argst);
}

char	*ft_fixops_s(char *argst, t_flags fg, t_ops sv)
{
	if (!argst)
		return (NULL);
	if (sv.precis)
		argst = ft_s_precis(argst, sv.precis);
	if (sv.conv == '%' && sv.precis == -1)
	{
		ft_strdel(&argst);
		argst = ft_strset('%', 1);
	}
	if (sv.conv == 'c' && !ft_strlen_p(argst))
		--sv.chp;
	argst = ft_s_fgchp(argst, fg, sv.chp);
	return (argst);
}
