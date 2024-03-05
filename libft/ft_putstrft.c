/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:41:49 by Alfofern          #+#    #+#             */
/*   Updated: 2022/12/31 17:41:53 by Alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrft(char *s, int *count)
{
	if (s == NULL)
	{
		write (1, "(null)", 6);
		*count += 6;
		return ;
	}
	else
	{
		while (*s)
		{
			write (1, s++, 1);
			*count += 1;
		}
	}
}
