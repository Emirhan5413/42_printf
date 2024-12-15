/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 03:43:23 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/09 03:44:14 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(unsigned long p)
{
	int	len;

	len = 0;
	if (p >= 16)
		len += ft_pointer(p / 16);
	len += write(1, &LOWER[p % 16], 1);
	return (len);
}

int	print_pointer(unsigned long p)
{
	int	len;

	len = 0;
	if (p == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += print_string("0x");
		len += ft_pointer(p);
	}
	return (len);
}
