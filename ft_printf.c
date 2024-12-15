/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:16:14 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/09 03:40:01 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (format == 'c')
		printed_chars += print_char(va_arg(args, int));
	else if (format == 's')
		printed_chars += print_string(va_arg(args, char *));
	else if (format == 'p')
		printed_chars += print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		printed_chars += print_int(va_arg(args, int));
	else if (format == 'u')
		printed_chars += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		printed_chars += print_hex(va_arg(args, unsigned int), LOWER);
	else if (format == 'X')
		printed_chars += print_hex(va_arg(args, unsigned int), UPPER);
	return (printed_chars);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	printed_chars;

	printed_chars = 0;
	if (!input)
		return (0);
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == '%')
				printed_chars += print_char('%');
			else if (ft_strchr("cspdiuxX", *input))
				printed_chars += check_format(*input, args);
		}
		else
			printed_chars += print_char(*input);
		input++;
	}
	va_end(args);
	return (printed_chars);
}
