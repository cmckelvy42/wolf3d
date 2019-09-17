/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:52:33 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/16 19:06:07 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list *ptr;
	t_list *ptr2;
	t_list *next;

	ptr = *begin_list;
	while (ptr)
	{
		ptr2 = *begin_list;
		while (ptr2->next)
		{
			if ((*cmp)(ptr2->content, ptr2->next->content) > 0)
			{
				next = ptr2->content;
				ptr2->content = ptr2->next->content;
				ptr2->next->content = next;
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}
