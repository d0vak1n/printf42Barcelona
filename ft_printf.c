/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:39:07 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/29 12:40:41 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libprintf.h"

static int	_format(char const *str, void *arg)
{
	int	numchars;

	numchars = 0;
	if (*str == 'c')
		numchars += ft_putchar_pf((char)arg);
	return (numchars);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int numchars;
	int	i;

	i = -1;
	numchars = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i++] == '%')
		{
			if (ft_strchr("cspdiuxX", str[i]))
				numchars += _format(&str[i], va_arg(args,  void *));
			else if (str[i] == '%')
				numchars += ft_putchar_pf('%');
		}
		else
			numchars += ft_putchar_pf(str[i]);
	}
	va_end(args);
	return (numchars);

}
