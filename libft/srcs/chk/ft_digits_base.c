/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:15:00 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/04 15:21:48 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digits_base(int n, int base)
{
	int digits;

	if (!n)
		return (1);
	digits = 0;
	while (n)
	{
		n /= base;
		digits++;
	}
	return (digits);
}
