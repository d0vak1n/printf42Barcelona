/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low_or_up.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:54:27 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/20 12:55:27 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	_numlen(unsigned int h)
{
	int	string_lenght;

	string_lenght = 1;
	while (h >= 16)
	{
		h /= 16;
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
int	ft_print_hex_low_or_up(unsigned int h, int option)
{
	int		i;
	int		len;
	char	*hexup;
	char	*hexlow;
	char	*res;

	hexlow = "0123456789abcdef";
	hexup = "0123456789ABCDEF";
	res = _create_str(h);
	if (!res)
		return (0);
	i = _numlen(h) - 1;
	while (i >= 0)
	{
		if (option == 0)
			res[i] = hexlow[h % 16];
		else
			res[i] = hexup[h % 16];
		h /= 16;
		i--;
	}
	len = ft_print_string(res);
	free(res);
	return (len);
}
