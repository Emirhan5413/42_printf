/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:26:57 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 03:41:49 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += print_int(n / 10);
	}
	count += print_char((n % 10) + '0');
	return (count);
}
