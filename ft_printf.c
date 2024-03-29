/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:39:07 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/13 21:56:45 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_format(char const *str, void *arg)
{
	int	numchars;

	numchars = 0;
	if (*str == 'c')
		numchars += ft_print_char((int)arg);
	if (*str == 's')
		numchars += ft_print_string((char *)arg);
	if (*str == 'p')
		numchars += ft_print_pointer((unsigned long int)arg);
	if (*str == 'd')
		numchars += ft_print_num((int)arg);
	if (*str == 'i')
		numchars += ft_print_num((int)arg);
	if (*str == 'u')
		numchars += ft_print_unsigned((unsigned int)arg);
	if (*str == 'x')
		numchars += ft_print_hex_low_or_up((unsigned int)arg, 0);
	if (*str == 'X')
		numchars += ft_print_hex_low_or_up((unsigned int)arg, 1);
	return (numchars);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		numchars;
	int		i;

	i = -1;
	numchars = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX", str[i + 1]))
				numchars += _format(&str[i + 1], va_arg(args, void *));
			else if (str[i + 1] == '%')
				numchars += ft_print_char('%');
			i++;
		}
		else
			numchars += ft_print_char(str[i]);
	}
	va_end(args);
	return (numchars);
}
