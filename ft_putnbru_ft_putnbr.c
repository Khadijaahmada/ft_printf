/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_ft_putnbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:32:47 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/21 20:12:58 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(int long nbr, int *len)
{
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		*len += 1;
	}
	return (*len);
}

int	ft_putnbr(int n)
{
	int long	nbr;
	int			digit;
	int			len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		len++;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		digit = nbr + 48;
		write(1, &digit, 1);
	}
	return (count(nbr, &len));
}

static	int	count_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbru(unsigned int nbr)
{
	int			digit;

	if (nbr > 9)
	{
		ft_putnbru(nbr / 10);
		ft_putnbru(nbr % 10);
	}
	else
	{
		digit = nbr + 48;
		write(1, &digit, 1);
	}
	return (count_u (nbr));
}
