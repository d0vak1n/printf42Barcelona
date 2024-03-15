/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:41:58 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/14 10:42:16 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
static int	_numdigits(unsigned int n)
{
	int	counter;

	counter = 1;
	if (n == UINT_MAX)
	{
		counter = 10;
		return (10);
	}
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	_print(unsigned int u)
{
	int	dnum;

	if (u == UINT_MAX)
	{
		ft_print_string("4294967295");
		return ;
	}
	if (u >= 10)
	{
		dnum = u % 10;
		u /= 10;
		_print(u);
	}
	else
		dnum = u;
	dnum += '0';
	ft_print_char(dnum);
}

int	ft_print_unsigned(unsigned int u)
{
	_print(u);
	return (_numdigits(u));
}