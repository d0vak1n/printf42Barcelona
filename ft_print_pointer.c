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

int	ft_print_pointer(unsigned long int address)
{
	int					len;

	len = 0;
	len = ft_print_string("0x");
	len += ft_print_hex_low(address);
	return (len);
}
