/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:08:21 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/07 15:09:23 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_int_tab(int **tab, size_t size, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (tab)
	{
		while (i < size)
		{
			while (j < len)
			{
				ft_putnbr(tab[i][j]);
				j++;
			}
			j = 0;
			ft_putchar('\n');
			i++;
		}
	}
}
