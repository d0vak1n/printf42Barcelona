/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:17 by ramoreno          #+#    #+#             */
/*   Updated: 2024/01/18 12:16:01 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*reserva;

	i = 0;
	if (n == 0)
		return ;
	reserva = (char *)s;
	while (i < n)
	{
		*reserva = '\0';
		i++;
		reserva++;
	}
}
/*
int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("\nBefore bzero(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    ft_bzero(str + 2, 5);

    printf("After bzero():  %s\n", str);
	return (0);
}*/
