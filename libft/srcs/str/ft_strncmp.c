/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:16:15 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:12:17 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (n == 0)
		return (0);
	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while ((*tmp1 && (*tmp1 == *tmp2)) && --n)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
