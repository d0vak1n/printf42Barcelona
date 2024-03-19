/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:56:25 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/22 10:33:18 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	char	*reserva;

	reserva = (char *)s;
	if (!s || !f)
		return ;
	i = -1;
	while (reserva[++i] != '\0')
		(*f)(i, &reserva[i]);
}
