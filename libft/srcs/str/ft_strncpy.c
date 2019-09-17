/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:46:51 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:41:54 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
