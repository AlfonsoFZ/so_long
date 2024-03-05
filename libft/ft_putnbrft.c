/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:50:12 by Alfofern          #+#    #+#             */
/*   Updated: 2022/12/31 17:51:27 by Alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrft(int n, int *count)
{
	long	nu;

	nu = (long) n;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
		*count += 11;
	}
	else if ((n < 0) && (n != -2147483648))
	{
		ft_putcharft('-', count);
		ft_putnbrft(nu * -1, count);
	}
	else if (nu > 9)
	{
		ft_putnbrft(nu / 10, count);
		ft_putnbrft(nu % 10, count);
	}
	else if (nu < 10)
		ft_putcharft(nu % 10 + '0', count);
}
