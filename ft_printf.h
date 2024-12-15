/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:16:37 by eunlu             #+#    #+#             */
/*   Updated: 2024/12/09 03:40:31 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"

int		ft_printf(const char *input, ...);
int		print_char(int c);
int		print_string(char *s);
int		print_pointer(unsigned long p);
int		print_int(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int nbr, const char *base);
char	*ft_strchr(const char *s, int c);

#endif