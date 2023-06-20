/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:12:36 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/28 17:15:50 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_ret;
	t_list	*elem;

	lst_ret = NULL;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
			ft_lstclear(&elem, (*del));
		else
			ft_lstadd_back(&lst_ret, elem);
		lst = lst->next;
	}
	return (lst_ret);
}
