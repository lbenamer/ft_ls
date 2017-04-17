/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:36:07 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 15:36:10 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_s_fgchp(char *argst, t_flags fg, int chp)
{
	char	*st_chp;
	int		len_chp;

	st_chp = NULL;
	if ((len_chp = chp - (int)ft_strlen_p(argst)) > 0)
	{
		st_chp = ft_strset(' ', len_chp);
		if (fg.less)
			argst = ft_strjoinf(argst, st_chp, 3);
		else
			argst = ft_strjoinf(st_chp, argst, 3);
	}
	return (argst);
}

char	*ft_oct_fgchp(char *argst, t_flags fg, int chp, int precis)
{
	int		len_chp;
	char	*st_chp;

	st_chp = NULL;
	if (fg.hstg)
		argst = ft_strjoinf("0", argst, 2);
	if ((fg.less && fg.zero) || (precis && (chp > precis)))
		fg.zero = 0;
	if ((len_chp = chp - ft_strlen_p(argst)) > 0)
	{
		if (fg.zero)
			st_chp = ft_strset('0', len_chp);
		else
			st_chp = ft_strset(' ', len_chp);
		if (fg.less)
			argst = ft_strjoinf(argst, st_chp, 3);
		else
			argst = ft_strjoinf(st_chp, argst, 3);
	}
	return (argst);
}

char	*ft_x_fgchp(char *argst, t_flags fg, int chp, int precis)
{
	int		len_chp;
	char	*st_chp;

	st_chp = NULL;
	if (fg.hstg && ft_strlen_p(argst) && ft_strcmp(argst, "0"))
		argst = ft_strjoinf("0x", argst, 2);
	if ((fg.less && fg.zero) || (precis && (chp > precis)))
		fg.zero = 0;
	if ((len_chp = chp - ft_strlen_p(argst)) > 0)
	{
		if (fg.zero)
			st_chp = ft_strset('0', len_chp);
		else
			st_chp = ft_strset(' ', len_chp);
		if (fg.less)
			argst = ft_strjoinf(argst, st_chp, 3);
		else if (fg.zero && fg.hstg)
		{
			ft_swap_c(&st_chp[1], &argst[1]);
			argst = ft_strjoinf(st_chp, argst, 3);
		}
		else
			argst = ft_strjoinf(st_chp, argst, 3);
	}
	return (argst);
}

char	*ft_unsgd_fgchp(char *argst, t_flags fg, int chp, int precis)
{
	char	*st_chp;
	int		len_chp;

	((fg.less && fg.zero) || (precis && (chp > precis))) ? fg.zero = 0 : 0;
	if (fg.plus)
		argst = ft_strjoinf("+", argst, 2);
	if (fg.space && !fg.plus)
		argst = ft_strjoinf(" ", argst, 2);
	if ((len_chp = chp - ft_strlen_p(argst)) > 0)
	{
		if (fg.zero)
			st_chp = ft_strset('0', len_chp);
		else
			st_chp = ft_strset(' ', len_chp);
		if (fg.less)
			argst = ft_strjoinf(argst, st_chp, 3);
		else if (fg.zero && (fg.plus || fg.space))
		{
			ft_swap_c(&st_chp[0], &argst[0]);
			argst = ft_strjoinf(st_chp, argst, 3);
		}
		else
			argst = ft_strjoinf(st_chp, argst, 3);
	}
	return (argst);
}

char	*ft_sgd_fgchp(char *argst, t_flags f, int chp, int precis)
{
	int		len_chp;
	char	*stchp;
	char	*negst;

	len_chp = 0;
	stchp = NULL;
	negst = NULL;
	if ((f.less && f.zero) || (precis && (chp > precis)))
		f.zero = 0;
	if ((len_chp = chp - ft_strlen_p(argst)) > 0)
	{
		negst = ft_strdup("-");
		argst = ft_strsub_f(argst, 1, ft_strlen_p(argst) - 1);
		if (f.zero)
			stchp = ft_strset('0', len_chp);
		else
			stchp = ft_strset(' ', len_chp);
		if (f.less)
			argst = ft_joinstr(negst, 3, 2, argst, stchp);
		else if (!f.less && f.zero)
			argst = ft_joinstr(negst, 3, 2, stchp, argst);
		else
			argst = ft_joinstr(stchp, 3, 2, negst, argst);
	}
	return (argst);
}
