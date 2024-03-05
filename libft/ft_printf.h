/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:12:52 by alfofern          #+#    #+#             */
/*   Updated: 2022/12/31 17:36:43 by Alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *pholders, ...);
void	ft_putcharft(char c, int *count);
void	ft_putstrft(char *s, int *count);
void	ft_putnbrft(int n, int *count);
void	ft_putnbruft(unsigned int n, int *count);
void	ft_putnbrx(unsigned int n, int *count);
void	ft_putnbrcx(unsigned int n, int *count);
void	ft_putpointerft(void *ptr, int *count);

#endif	