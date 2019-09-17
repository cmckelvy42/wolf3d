/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:49:36 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/19 15:04:23 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int sign;

	n = 0;
	sign = 1;
	if (!(*str))
		return (0);
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\r' ||
	*str == '\v' || *str == '\f')
	{
		++str;
	}
	if ((*str) == '-' || (*str) == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * sign);
}
