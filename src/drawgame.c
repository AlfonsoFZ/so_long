/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:04:44 by alfofern          #+#    #+#             */
/*   Updated: 2023/05/26 20:49:08 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_drawelement(t_dt *dt, mlx_image_t *elem, int x, int y)
{
	mlx_image_to_window(dt->mlx, elem, (x * SPR), (y * SPR));
}

void	ft_drawgame(t_dt *dt)
{
	dt->i = 0;
	while (dt->i < dt->y)
	{
			dt->j = 0;
		while (dt->j < dt->x)
		{
			if (dt->rmap[dt->i][dt->j] == '0')
				ft_drawelement(dt, dt->f_img, dt->j, dt->i);
			else if (dt->rmap[dt->i][dt->j] == '1')
				ft_drawelement(dt, dt->w_img, dt->j, dt->i);
			else if (dt->rmap[dt->i][dt->j] == 'P')
			{
				ft_drawelement(dt, dt->f_img, dt->j, dt->i);
				ft_drawelement(dt, dt->p_img_up, dt->j, dt->i);
			}
			else if (dt->rmap[dt->i][dt->j] == 'C')
				ft_drawelement(dt, dt->c_img, dt->j, dt->i);
			else if (dt->rmap[dt->i][dt->j] == 'E')
				ft_drawelement(dt, dt->e_img, dt->j, dt->i);
			dt->j++;
		}
		dt->i++;
	}
}

void	ft_loadpngs(t_dt *dt)
{
	dt->text_floor = mlx_load_png("img/floor.png");
	dt->text_wall = mlx_load_png("img/wall.png");
	dt->text_player = mlx_load_png("img/player1.png");
	dt->text_play_left = mlx_load_png("img/player1left.png");
	dt->text_player2 = mlx_load_png("img/player2.png");
	dt->text_play_left2 = mlx_load_png("img/player2left.png");
	dt->text_play_down = mlx_load_png("img/Rabbit_Up.png");
	dt->text_play_up = mlx_load_png("img/Rabbit_Down.png");
	dt->text_e = mlx_load_png("img/exit.png");
	dt->text_obj = mlx_load_png("img/collect.png");
}

void	ft_texturize(t_dt *dt)
{
	dt->f_img = mlx_texture_to_image(dt->mlx, dt->text_floor);
	dt->w_img = mlx_texture_to_image(dt->mlx, dt->text_wall);
	dt->p_img = mlx_texture_to_image(dt->mlx, dt->text_player);
	dt->p_2img = mlx_texture_to_image(dt->mlx, dt->text_player2);
	dt->p_img_up = mlx_texture_to_image(dt->mlx, dt->text_play_up);
	dt->p_img_down = mlx_texture_to_image(dt->mlx, dt->text_play_down);
	dt->p_img_left = mlx_texture_to_image(dt->mlx, dt->text_play_left);
	dt->p_img_left2 = mlx_texture_to_image(dt->mlx, dt->text_play_left2);
	dt->e_img = mlx_texture_to_image(dt->mlx, dt->text_e);
	dt->c_img = mlx_texture_to_image(dt->mlx, dt->text_obj);
	mlx_delete_texture(dt->text_wall);
	mlx_delete_texture(dt->text_floor);
	mlx_delete_texture(dt->text_player);
	mlx_delete_texture(dt->text_player2);
	mlx_delete_texture(dt->text_play_left);
	mlx_delete_texture(dt->text_play_left2);
	mlx_delete_texture(dt->text_play_up);
	mlx_delete_texture(dt->text_play_down);
	mlx_delete_texture(dt->text_e);
	mlx_delete_texture(dt->text_obj);
}

void	ft_startthegame(t_dt *dt)
{
	dt->mlx = mlx_init(dt->x * SPR, dt->y * SPR, "so_long", false);
	ft_loadpngs(dt);
	ft_texturize(dt);
	ft_drawgame(dt);
	mlx_key_hook(dt->mlx, &ft_movekeys, dt);
	mlx_loop(dt->mlx);
}
