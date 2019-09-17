/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:16:12 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/03/04 15:23:14 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	char	*result;
	int		sign;
	int		len;

	sign = 1;
	if (n < 0)
		sign = 2;
	len = ft_digits_base(n, base) + (sign - 1);
	if (sign == 2)
		sign -= 3;
	if (!(result = (char*)ft_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	len--;
	while (n)
	{
		result[len] = (n % base) * sign + (n % base > 9 ? 'A' - 10 : '0');
		n /= base;
		len--;
	}
	if (sign == -1)
		result[len] = '-';
	return (result);
}
