/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:33:37 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/06 10:38:17 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libprintf.h"

int	ft_putchar_pf(char const c)
{
	int	len;

	len = write(1, &c, 1);
	if (len == -1)
		return (-1);
	else
		return len;
}
