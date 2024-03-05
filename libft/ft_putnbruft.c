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

void	ft_putnbruft(unsigned int n, int *count)
{
	unsigned long	nu;

	nu = (unsigned long) n;
	if (nu > 9)
	{
		ft_putnbruft(nu / 10, count);
		ft_putnbruft(nu % 10, count);
	}
	else if (nu < 10)
		ft_putcharft(nu % 10 + '0', count);
}
