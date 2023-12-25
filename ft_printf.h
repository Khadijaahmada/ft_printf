/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:03:08 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/21 15:47:22 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(int c);
int		ft_putstring(char *str);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int nbr);
int		ft_printf_ptr(unsigned long ptr);
int		ft_printf_hexadecimal(unsigned int num, const char format);
int		ft_printf_int(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_printf_percent(void);
int		ft_putnbru(unsigned int nbr);
#endif
