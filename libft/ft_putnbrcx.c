/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:53:29 by Alfofern          #+#    #+#             */
/*   Updated: 2022/12/31 17:54:21 by Alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrcx(unsigned int n, int *count)
{
	if (n > 15)
	{
		ft_putnbrcx (n / 16, count);
		ft_putcharft ("0123456789ABCDEF"[n % 16], count);
	}
	else if (n < 16)
		ft_putcharft ("0123456789ABCDEF"[n % 16], count);
}
