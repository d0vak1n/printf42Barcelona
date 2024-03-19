/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:03:27 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/13 13:03:30 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_numlen(unsigned long p)
{
	int	string_lenght;

	string_lenght = 1;
	while (p >= 16)
	{
		p /= 16;
		string_lenght++;
	}
	return (string_lenght);
}

static char	*_create_str(unsigned long long p)
{
	char	*str;
	int		string_lenght;

	string_lenght = _numlen(p);
	str = ft_calloc((string_lenght + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

int	ft_print_hex_low(unsigned long long h)
{
	int		i;
	int		len;
	char	*hex;
	char	*res;

	hex = "0123456789abcdef";
	res = _create_str(h);
	if (!res)
		return (0);
	i = _numlen(h) - 1;
	while (i >= 0)
	{
		res[i] = hex[h % 16];
		h /= 16;
		i--;
	}
	len = ft_print_string("0x");
	len += ft_print_string(res);
	free(res);
	return (len);
}
