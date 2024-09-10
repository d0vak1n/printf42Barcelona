/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:39:07 by ramoreno          #+#    #+#             */
/*   Updated: 2024/09/10 15:25:21 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"
#include <stdarg.h>

static int	_format(char const *str, va_list args)
{
	int	numchars;

	numchars = 0;
	if (*str == 'c')
		numchars += ft_print_char((char)va_arg(args, int));
	else if (*str == 's')
		numchars += ft_print_string(va_arg(args, char *));
	else if (*str == 'p')
		numchars += ft_print_pointer(va_arg(args, unsigned long int));
	else if (*str == 'd' || *str == 'i')
		numchars += ft_print_num(va_arg(args, int));
	else if (*str == 'u')
		numchars += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x')
		numchars += ft_print_hex_low_or_up(va_arg(args, unsigned int), 0);
	else if (*str == 'X')
		numchars += ft_print_hex_low_or_up(va_arg(args, unsigned int), 1);
	return (numchars);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		numchars;
	int		i;

	i = 0;
	numchars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX", format[i]))
				numchars += _format(&format[i], args);
			else if (format[i] == '%')
				numchars += ft_print_char('%');
		}
		else
			numchars += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (numchars);
}
