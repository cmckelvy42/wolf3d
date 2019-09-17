/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:20:22 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:12:17 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		i;
	int		len;
	int		numwords;

	if (!s)
		return (NULL);
	i = 0;
	numwords = ft_wordcount(s, c);
	if (!(strings = (char**)ft_memalloc((numwords + 1) * sizeof(char*))))
		return (NULL);
	while (numwords--)
	{
		while (*s == c && *s)
			s++;
		len = ft_wordlen(s, c);
		if (!(strings[i] = ft_strsub(s, 0, len)))
			return (NULL);
		s += len;
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
