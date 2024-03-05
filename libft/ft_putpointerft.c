/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointerft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:55:24 by Alfofern          #+#    #+#             */
/*   Updated: 2023/01/09 09:25:35 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointerft(void *ptr, int *count)
{
	unsigned long long	temp;

	temp = (unsigned long long)ptr;
	if (temp > 15)
	{
		ft_putpointerft((void *)(temp / 16), count);
		ft_putpointerft((void *)(temp % 16), count);
	}
	else
		ft_putcharft("0123456789abcdef"[temp % 16], count);
}
