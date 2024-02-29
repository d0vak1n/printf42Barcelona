/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:24:38 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/15 13:25:32 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	_countwords(char const *str, char c)
{
	int		counter;

	counter = 0;
	while (*str)
	{
		if (*str != c)
		{
			counter++;
			while (*str != c && *str)
				str++;
		}
		if (*str == c && *str)
			while (*str == c && *str)
				str++;
	}
	return (counter);
}

static char	*_separateword(char const *str, char c, int const index)
{
	char	*res;
	int		counter;
	int		end;
	int		i;

	counter = 0;
	i = 0;
	end = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (counter++ == index)
		{
			while (str[i + end] != c && str[i + end] != '\0')
				end++;
			res = ft_substr(&str[i], 0, end);
			return (res);
		}
		while (str[i] != c && str[i] != '\0')
			++i;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		row;
	int		words;
	char	**res;

	row = -1;
	words = _countwords(s, c);
	if (!s)
		return (NULL);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[words] = NULL;
	while (++row < words)
	{
		res[row] = _separateword(s, c, row);
		if (!res[row])
		{
			while (--row >= 0)
				free(res[row]);
			free(res);
			return (NULL);
		}
	}
	return (res);
}
