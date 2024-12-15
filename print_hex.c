/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:27:45 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 03:41:16 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nbr, const char *hex_base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += print_hex(nbr / 16, hex_base);
	count += write(1, &hex_base[nbr % 16], 1);
	return (count);
}
