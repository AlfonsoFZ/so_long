/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:36 by jmerchan          #+#    #+#             */
/*   Updated: 2023/05/31 19:48:12 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>

# define WRONG_ARG "Please include a \".ber map\" after the programm name\n"
# define EXT_ACCESS "wrong file extension or inaccessible file\n"
# define OPEN_ERR "The map cannot be opened"
# define MAP_BORDER "The map is not valid, borders aren't closed.\n"
# define INVALID_CHAR "I've found invalid characters in map\n"
# define INVALID_SHAPE "non-symmetric map\n"
# define INVALID_NITEMS "Wrong ammount of players, collectables and/or exit.\n"
# define NOT_PLAY "The map cannot be played\n"
# define SPR 64

typedef struct s_dt
{
	char			*mapfile;
	int				mapfd;
	int				obj;
	int				end;
	int				movs;
	int				side;
	int				x;
	int				y;
	int				play;
	int				x_play;
	int				y_play;
	int				play_new_x;
	int				play_new_y;
	int				play_old_x;
	int				play_old_y;	
	char			**rmap;
	char			**cp_map;
	int				dir;
	int				i;
	int				j;
	mlx_t			*mlx;
	mlx_image_t		*w_img;
	mlx_image_t		*f_img;
	mlx_image_t		*p_img;
	mlx_image_t		*p_2img;
	mlx_image_t		*p_img_left;
	mlx_image_t		*p_img_left2;
	mlx_image_t		*p_img_up;		
	mlx_image_t		*p_img_down;	
	mlx_image_t		*e_img;
	mlx_image_t		*c_img;
	mlx_texture_t	*text_wall;
	mlx_texture_t	*text_floor;
	mlx_texture_t	*text_player;
	mlx_texture_t	*text_player2;
	mlx_texture_t	*text_play_left;
	mlx_texture_t	*text_play_left2;
	mlx_texture_t	*text_play_up;
	mlx_texture_t	*text_play_down;
	mlx_texture_t	*text_e;
	mlx_texture_t	*text_obj;
}	t_dt;

//checkmap_content.c
void	ft_chkborder(t_dt *dt);
void	ft_chkitems(t_dt *dt);
void	ft_chkshape(t_dt *dt);
void	ft_chkemptyline(char *map);

//checkmapfile_and_path.c
int		ft_checkext(char *filename, char *ext);
char	*ft_checkfile(char *map);
void	ft_checkpath(t_dt *dt);
void	ft_chkpath(t_dt *dt);

/*utils.c*/
void	ft_msgerr(char *msg);
void	ft_free_error(t_dt *dt);
void	ft_initdt(t_dt *dt);
void	ft_free_double_pointer(char **pointer);
void	ft_free_dt(t_dt *dt);

//drawgame.c
void	ft_drawelement(t_dt *dt, mlx_image_t *elem, int x, int y);
void	ft_drawgame(t_dt *dt);
void	ft_loadpngs(t_dt *dt);
void	ft_texturize(t_dt *dt);
void	ft_startthegame(t_dt *dt);

//movements.c

void	ft_move_direction(t_dt *dt);
void	ft_move(t_dt *dt);
void	ft_movekeys(mlx_key_data_t keydata, void *param);

//updategame.c
void	ft_updategame(t_dt *dt, int y, int x);
void	ft_updategameleft(t_dt *dt, int y, int x);
void	ft_updategameup(t_dt *dt, int y, int x);
void	ft_updategamedown(t_dt *dt, int y, int x);
void	ft_finishgame(t_dt *dt);

#endif