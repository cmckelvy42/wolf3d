/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 17:06:56 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:41:06 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (*tmp1 && (*tmp1 == *tmp2))
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
