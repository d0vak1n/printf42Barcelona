/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:49:48 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/12 12:50:54 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"


static char	*_create_str(unsigned long p)
{

}

int	ft_print_pointer(unsigned long p)
{
	int	div;
	int	rest;
	char *hex;

	hex = "0123456789abcdef";

	if (p < 16)
	{
		p /= 16;
		rest = p % 16;
		ft_print_pointer(rest);
	}
	else
		ft_print_char(hex[p]);
}

