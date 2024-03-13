/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:42:14 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/13 21:42:14 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	numdigits(int n)
{
	int	counter;

	counter = 1;
	if (n == INT_MIN)
	{
		counter = 11;
		return (11);
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

int ft_print_num(int n)
{
    ft_putnbr_fd(n, 1);
    return (numdigits(n));
}