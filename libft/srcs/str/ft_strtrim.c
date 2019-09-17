/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:10:17 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:43:05 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len - 1]))
		len--;
	len = len - i;
	if (!(new = (char*)ft_strnew(len >= 0 ? len : 0)))
		return (NULL);
	j = -1;
	while (++j < len)
		new[j] = s[i + j];
	new[j] = '\0';
	return (new);
}
