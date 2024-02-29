/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:25:17 by ramoreno          #+#    #+#             */
/*   Updated: 2024/02/29 12:31:10 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(char const *str, ...);

#endif