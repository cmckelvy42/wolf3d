/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:27:43 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/17 17:37:52 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		if (!(new = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			new[i] = f(i, s[i]);
			i++;
		}
		return (new);
	}
	return (NULL);
}
