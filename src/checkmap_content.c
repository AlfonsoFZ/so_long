/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:09:21 by alfofern          #+#    #+#             */
/*   Updated: 2023/06/05 19:01:57 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_chkborder(t_dt *dt)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < dt->x && j < dt->y)
	{
		if (dt->rmap[0][i] != '1' || dt->rmap[dt->y - 1][i] != '1'
			|| dt->rmap[j][0] != '1' || dt->rmap[j][dt->x - 1] != '1')
		{
			ft_free_double_pointer(dt->rmap);
			ft_msgerr(MAP_BORDER);
		}
		i++;
		j++;
		if (i == dt->x && j != dt->y)
			i--;
		if (j == dt->y && i != dt->x)
			j--;
	}
}

/** check the items and initalizes variables
 * xplay, yplay, where the player begins, add one unit to 
 * player (P), obj (C) and nextit (E).
 * call the INVALID_CHAR error if there are any items diferent to 
 * 0 or INVALID _NELEMENTS if play != 1 || obj < 1 || end != 1
*/
void	ft_chkitems(t_dt *dt)
{
	int	i;
	int	j;

	i = 0;
	while (++i < dt->y - 1)
	{
		j = 0;
		while (++j < dt->x - 1)
		{
			if (dt->rmap[i][j] == 'P')
			{
				dt->play++;
				dt->x_play = j;
				dt->y_play = i;
			}
			else if (dt->rmap[i][j] == 'E')
				dt->end++;
			else if (dt->rmap[i][j] == 'C')
				dt->obj++;
			else if (dt->rmap[i][j] != '0' && dt->rmap[i][j] != '1')
				ft_msgerr(INVALID_CHAR);
		}
	}
	if (dt->play != 1 || dt->obj < 1 || dt->end != 1)
		ft_msgerr(INVALID_NITEMS);
}

void	ft_chkshape(t_dt *dt)
{
	int		i;

	i = 0;
	dt->x = ft_strlen(dt->rmap[0]);
	while (dt->rmap[i] != 0)
	{
		if ((size_t)dt->x != ft_strlen(dt->rmap[i]))
			ft_msgerr(INVALID_SHAPE);
		i++;
	}
	dt->y = i;
	ft_chkborder(dt);
	ft_chkitems(dt);
}

void	ft_chkemptyline(char *map)
{
	int	i;

	i = 0;
	if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_msgerr("Empty line at the end of the map");
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_msgerr("Empty line in the middle of the map");
		}
		i++;
	}
}
