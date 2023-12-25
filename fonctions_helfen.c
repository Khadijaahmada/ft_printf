/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_helfen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:55:47 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/20 18:34:26 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
}

int	ft_putstring(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_printf_percent(void)
{
	write(1, "%", 1);
	return (1);
}
