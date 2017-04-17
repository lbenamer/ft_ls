/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 23:59:26 by lbenamer          #+#    #+#             */
/*   Updated: 2017/01/30 23:59:28 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa(long n)
{
	long	i;
	char	*tab;
	long	nb;

	i = 0;
	nb = n;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	n < 0 ? ++i : i;
	n < 0 ? nb = -n : 0;
	n < 0 ? n = -n : 0;
	while (n >= 1 && ++i)
		n = n / 10;
	if (!(tab = ft_strnew(i)))
		return (NULL);
	tab[i--] = '\0';
	while (nb > 0)
	{
		tab[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	i == 0 ? tab[i] = '-' : 0;
	return (tab);
}
