/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:32:43 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/22 19:54:37 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length = length + ft_putchar(va_arg(args, int));
	else if (format == 's')
		length = length + ft_putstring(va_arg(args, char *));
	else if (format == 'p')
		length = length + ft_printf_ptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		length = length + ft_printf_int(va_arg(args, int));
	else if (format == 'u')
		length = length + ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length = length + ft_printf_hexadecimal(va_arg(args, unsigned int),
				format);
	else if (format == '%')
		length = length + ft_printf_percent();
	else
	{
		length += ft_putchar(format);
	}
	return (length);
}

static int	ft_putinput(const char *input, int *length, int *i, va_list args)
{
	int	result;

	result = 0;
	if (input[*i] == '%' && input[*i + 1] != '\0')
	{
		result = ft_formats(args, input[*i + 1]);
		if (result == -1)
		{
			return (-1);
		}
		*length += result;
		(*i)++;
	}
	else if (input[*i] != '%')
	{
		result = ft_putchar(input[*i]);
		if (result == -1)
		{
			return (-1);
		}
		*length += result;
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		length;
	int		result;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, input);
	if (write(1, "", 0) == -1)
		return (-1);
	while (input[i] != '\0')
	{
		result = ft_putinput(input, &length, &i, args);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (length);
}
