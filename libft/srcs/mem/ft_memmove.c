/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 00:52:55 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:39:58 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*dest;

	i = -1;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source < dest)
		while ((int)(--n) >= 0)
			dest[n] = source[n];
	else
		while (++i < n)
			dest[i] = source[i];
	return (dest);
}
