/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:19:07 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:37:34 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = -1;
	if (s && f)
	{
		if (!(new = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			new[i] = f(s[i]);
		return (new);
	}
	return (NULL);
}
