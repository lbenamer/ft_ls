/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:56:13 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/20 15:56:14 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *tmp;
	t_list *tmp2;

	tmp = f(lst);
	if (!(map = ft_lstnew(tmp->content, tmp->content_size)) || !lst || !tmp)
		return (NULL);
	tmp2 = map;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		tmp2->next = ft_lstnew(tmp->content, tmp->content_size);
		tmp2 = tmp2->next;
		lst = lst->next;
	}
	return (map);
}
