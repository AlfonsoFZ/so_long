/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:57:21 by alfofern          #+#    #+#             */
/*   Updated: 2023/06/05 19:02:57 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_direction(t_dt *dt)
{
	if (dt->dir == 0)
	{
		ft_updategameleft(dt, dt->play_old_y, dt->play_old_x);
		ft_updategameleft(dt, dt->y_play, dt->x_play);
	}
	else if (dt->dir == 1)
	{
		ft_updategame(dt, dt->play_old_y, dt->play_old_x);
		ft_updategame(dt, dt->y_play, dt->x_play);
	}
	else if (dt->dir == 2)
	{
		ft_updategameup(dt, dt->play_old_y, dt->play_old_x);
		ft_updategameup(dt, dt->y_play, dt->x_play);
	}
	else if (dt->dir == 3)
	{
		ft_updategamedown(dt, dt->play_old_y, dt->play_old_x);
		ft_updategamedown(dt, dt->y_play, dt->x_play);
	}
	if (dt->dir == -1)
		dt->dir = -1;
}

void	ft_move(t_dt *dt)
{
	if (dt->rmap[dt->play_new_y][dt->play_new_x] == 'C')
		dt->obj--;
	if (dt->rmap[dt->play_new_y][dt->play_new_x] == 'C' ||
		dt->rmap[dt->play_new_y][dt->play_new_x] == '0')
	{
		dt->rmap[dt->y_play][dt->x_play] = '0';
		dt->rmap[dt->play_new_y][dt->play_new_x] = 'P';
		dt->play_old_x = dt->x_play;
		dt->play_old_y = dt->y_play;
		dt->x_play = dt->play_new_x;
		dt->y_play = dt->play_new_y;
		dt->movs++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(dt->movs, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (dt->rmap[dt->play_new_y][dt->play_new_x] == 'E')
		ft_finishgame(dt);
	ft_move_direction(dt);
}

static void	movement_plus(t_dt *dt, int axis, int dir)
{
	if (axis == 1 && (dir == -1 || dir == 1))
	{
		if ((dt->play_new_y + dir) > 0 && (dt->play_new_y + dir) < dt->y - 1)
		{
				dt->play_new_y = dt->play_new_y + dir;
			if (dir == -1)
				dt->dir = 2;
			else
				dt->dir = 3;
		}
	}
	else
	{	
		if (dt->play_new_x + dir > 0 && dt->play_new_x + dir < dt->x - 1)
		{
				dt->play_new_x = dt->play_new_x + dir;
			if (dir == -1)
				dt->dir = 0;
			else
				dt->dir = 1;
		}
	}
}

static void	movement(t_dt *dt, int axis, int dir)
{
	if (dt->movs == 0)
	{
		movement_plus(dt, axis, dir);
		return ;
	}
	if (axis == 1 && (dir == -1 || dir == 1))
	{
		dt->play_new_y = dt->play_new_y + dir;
		if (dir == -1)
			dt->dir = 2;
		else
			dt->dir = 3;
	}
	else
	{
		dt->play_new_x = dt->play_new_x + dir;
		if (dir == -1)
			dt->dir = 0;
		else
			dt->dir = 1;
	}
}

void	ft_movekeys(mlx_key_data_t keydata, void *param)
{
	t_dt	*dt;

	dt = param;
	dt->play_new_y = dt->y_play;
	dt->play_new_x = dt->x_play;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		movement(dt, 1, -1);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		movement(dt, 2, -1);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		movement(dt, 2, 1);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		movement(dt, 1, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	ft_move(dt);
	return ;
}
