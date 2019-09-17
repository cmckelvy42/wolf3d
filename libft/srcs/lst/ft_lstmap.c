/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:46:26 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/16 18:52:51 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin_list;

	if (!lst)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	begin_list = new;
	while (lst)
	{
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	return (begin_list);
}
