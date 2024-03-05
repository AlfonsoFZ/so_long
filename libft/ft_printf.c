/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:34:50 by alfofern          #+#    #+#             */
/*   Updated: 2023/01/09 09:25:09 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkandprint(char c, va_list args, int *count)
{
	if (c == 'c')
		ft_putcharft (va_arg(args, int), count);
	else if (c == 's')
		ft_putstrft (va_arg(args, char *), count);
	else if (c == 'u')
		ft_putnbruft (va_arg(args, unsigned int), count);
	else if (c == 'i' || c == 'd')
		ft_putnbrft (va_arg(args, int), count);
	else if (c == 'p')
	{
		ft_putstrft("0x", count);
		ft_putpointerft(va_arg(args, void *), count);
	}
	else if (c == 'x')
		ft_putnbrx (va_arg(args, int), count);
	else if (c == 'X')
		ft_putnbrcx (va_arg(args, int), count);
	else if (c == '%')
		ft_putcharft ('%', count);
	return (0);
}

int	ft_printf(char const *pholders, ...)
{
	int		i;
	va_list	args;
	int		*count;
	int		counter;

	if ((write (1, "", 0) == -1))
		return (-1);
	count = &counter;
	va_start(args, pholders);
	i = 0;
	*count = 0;
	while (pholders[i])
	{
		if (pholders[i] != '%')
			ft_putcharft(pholders[i], count);
		else if (pholders[i] == '%')
		{
			ft_checkandprint(pholders[i + 1], args, count);
			i++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}
