/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:12:24 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/12 12:13:58 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	len;
	int	i;
	int	err;

	i = -1;
	len = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[++i])
	{
		err = 0;
		err += ft_print_char(str[i]);
		if (err == -1)
			return (-1);
		else
			len += err;
	}
	return (len);
}
