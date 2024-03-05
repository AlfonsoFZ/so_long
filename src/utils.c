/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:58:49 by alfofern          #+#    #+#             */
/*   Updated: 2023/05/31 19:49:02 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_msgerr(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

void	ft_free_double_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

void	ft_free_dt(t_dt *dt)
{
	int	i;

	i = 0;
	while (dt->rmap[i])
		free(dt->rmap[i++]);
	free(dt->mapfile);
	free(dt->rmap);
}

void	ft_initdt(t_dt *dt)
{
	dt->end = 0;
	dt->play = 0;
	dt->obj = 0;
	dt->movs = 0;
	dt->side = 1;
	dt->dir = -1;
	dt->i = 0;
	dt->j = 0;
}
