/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoreno <ramoreno@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:25:17 by ramoreno          #+#    #+#             */
/*   Updated: 2024/03/13 21:50:14 by ramoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_print_char(char const c);
int	ft_print_string(char *str);
int	ft_print_pointer(void *p);
int ft_print_hex(unsigned long long h);
int ft_print_num(int n);

#endif