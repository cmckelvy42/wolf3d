/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:23:07 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/19 16:00:28 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0')
		k++;
	if (size <= i)
		k += size;
	else
		k += i;
	j = 0;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	dest[i] = '\0';
	return (k);
}
