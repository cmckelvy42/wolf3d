/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:59:30 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/19 15:15:02 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digits(int n)
{
	int digits;

	if (!n)
		return (1);
	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
