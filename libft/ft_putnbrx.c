/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:52:15 by Alfofern          #+#    #+#             */
/*   Updated: 2022/12/31 17:53:06 by Alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrx(unsigned int nb, int *count)
{
	unsigned long long	n;

	n = (unsigned long)nb;
	if (n > 15)
	{
		ft_putnbrx (n / 16, count);
		ft_putcharft ("0123456789abcdef"[n % 16], count);
	}
	else if (n < 16)
		ft_putcharft ("0123456789abcdef"[n % 16], count);
}
