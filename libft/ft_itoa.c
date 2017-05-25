/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:13:55 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/22 02:24:10 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*tab;
	int		nb;

	i = 0;
	nb = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n < 0 ? i++ : i;
	n < 0 ? nb = -n : +n;
	n < 0 ? n = -n : n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n >= 1 && ++i)
		n = n / 10;
	if (!(tab = (char*)malloc(sizeof(char) * i + 1)))
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
