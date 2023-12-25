/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:09:54 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/19 18:57:21 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_putptr_conv(unsigned long num)
{
	if (num >= 16)
	{
		ft_putptr_conv(num / 16);
		ft_putptr_conv(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}

int	ft_printf_ptr(unsigned long ptr)
{
	int	lengthp;

	lengthp = 0;
	lengthp += write(1, "0x", 2);
	if (ptr == 0)
		lengthp += write(1, "0", 1);
	else
	{
		lengthp += ft_ptr_len(ptr);
		ft_putptr_conv(ptr);
	}
	return (lengthp);
}
