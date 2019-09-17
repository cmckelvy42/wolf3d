/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:19:39 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/16 19:08:00 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = ft_memalloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		ft_memcpy((list->content), content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
