/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updategame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:45:03 by alfofern          #+#    #+#             */
/*   Updated: 2023/05/31 19:48:06 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_finishgame(t_dt *dt)
{
	if (dt->obj > 0)
		ft_putstr_fd("At least one carrot is pending to be collected\n", 1);
	else
	{
		ft_putstr_fd("YOU WIN\n", 1);
		exit (EXIT_SUCCESS);
	}
}

void	ft_updategame(t_dt *dt, int y, int x)
{
	if (dt->rmap[y][x] == '0')
		ft_drawelement(dt, dt->f_img, x, y);
	else if (dt->rmap[y][x] == 'P' && dt->movs % 2 == 0)
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_img, x, y);
	}
	else if (dt->rmap[y][x] == 'P' && dt->movs % 2 != 0)
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_2img, x, y);
	}
}

void	ft_updategameleft(t_dt *dt, int y, int x)
{
	if (dt->rmap[y][x] == '0')
		ft_drawelement(dt, dt->f_img, x, y);
	else if (dt->rmap[y][x] == 'P' && dt->movs % 2 == 0)
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_img_left, x, y);
	}
	else if (dt->rmap[y][x] == 'P' && dt->movs % 2 != 0)
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_img_left2, x, y);
	}
}

void	ft_updategameup(t_dt *dt, int y, int x)
{
	if (dt->rmap[y][x] == '0')
		ft_drawelement(dt, dt->f_img, x, y);
	else if (dt->rmap[y][x] == 'P')
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_img_down, x, y);
	}
}

void	ft_updategamedown(t_dt *dt, int y, int x)
{
	if (dt->rmap[y][x] == '0')
		ft_drawelement(dt, dt->f_img, x, y);
	else if (dt->rmap[y][x] == 'P')
	{
		ft_drawelement(dt, dt->f_img, x, y);
		ft_drawelement(dt, dt->p_img_up, x, y);
	}
}
