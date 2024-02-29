/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:18:10 by ramoreno          #+#    #+#             */
/*   Updated: 2024/01/18 12:59:03 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		*d = *s;
		i++;
		d++;
		s++;
	}
	return (dst);
}

/*int	main()
{
    char str1[50] = "GeeksForGeeks is for programming geeks.";
    char str2[50] = "Cosas";

    printf("\nBefore memcpy(): \n%s\n%s\n\n", str1, str2);


    char *fuedestino = ft_memcpy(str2, str1, 3);

    printf("After memcpy():  \n%s\n%s\n\n", str1, str2);

    printf("Destino antes():  %s\n", fuedestino);

    return 0;
}*/
