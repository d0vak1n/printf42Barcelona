/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:32:45 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/20 11:33:34 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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

static char	*minvalue(int min, char *str, int i)
{
	char	*numbar;

	numbar = "0123456789";
	str[0] = '-';
	str[1] = '2';
	min = 147483648;
	while (min > 0)
	{
		str[--i] = numbar[min % 10];
		min /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*numbar;
	int		i;

	i = numdigits(n);
	numbar = "0123456789";
	str = (char *)malloc((numdigits(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[numdigits(n)] = '\0';
	if (n == INT_MIN)
		return (minvalue(INT_MIN, str, i));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = numbar[n];
	while (n > 0)
	{
		str[--i] = numbar[n % 10];
		n /= 10;
	}
	return (str);
}
