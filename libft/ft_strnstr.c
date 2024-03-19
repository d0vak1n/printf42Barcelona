/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:52 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/05 15:44:44 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	char	*hays;

	i = 0;
	hays = (char *)haystack;
	if (needle[i] == '\0')
		return (hays);
	if (hays[i] == '\0')
		return (NULL);
	while (hays[i] != '\0' && i < len)
	{
		c = 0;
		while (hays[i + c] == needle[c] && hays[i + c] != 0 && (i + c) < len)
		{
			if (needle[c + 1] == '\0')
				return (&hays[i]);
			c++;
		}
		i++;
	}
	return (NULL);
}
