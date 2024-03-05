/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapfile_and_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:09:21 by alfofern          #+#    #+#             */
/*   Updated: 2023/06/05 19:02:17 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**this funtion check if a filename end with the extension provided
 * return 0 if the extension match else return 1. 
*/
int	ft_checkext(char *filename, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(filename);
	j = ft_strlen(ext);
	if (i < 5)
		return (1);
	while (j > 0)
		if (filename[--i] != ext[--j])
			return (1);
	return (0);
}

/**we call the function to check the extension and check that the map can be 
 * aceessed with the R_OK flag, returning the filename without spaces before 
 * or after it. 
*/
char	*ft_checkfile(char *map)
{
	char	*filename;

	filename = ft_strtrim(map, " ");
	if (ft_checkext(filename, ".ber") || (access(filename, R_OK) == -1))
	{
		free(filename);
		ft_msgerr(EXT_ACCESS);
	}
	return (filename);
}

/** fill each 0 with 1 and "spread" the function, if an E is found 
 * the functin stops so in case that a C is sorrounded by 1 and the E,
 * it will remain as a C, in this way we can check that we have a valid path
*/
static void	ft_floodfill_map(t_dt *dt, int x, int y)
{
	if (dt->cp_map[y][x] == 'E')
	{
		dt->cp_map[y][x] = '1';
		return ;
	}
	dt->cp_map[y][x] = '1';
	if (dt->cp_map[y][x + 1] != '1')
		ft_floodfill_map(dt, x + 1, y);
	if (dt->cp_map[y][x - 1] != '1')
		ft_floodfill_map(dt, x - 1, y);
	if (dt->cp_map[y + 1][x] != '1')
		ft_floodfill_map(dt, x, y + 1);
	if (dt->cp_map[y - 1][x] != '1')
		ft_floodfill_map(dt, x, y - 1);
}

void	ft_chkpath(t_dt *dt)
{
	int	i;

	i = 1;
	ft_floodfill_map(dt, dt->x_play, dt->y_play);
	while (i < dt->y -1)
	{
		if (ft_strchr(dt->cp_map[i], 'E') || ft_strchr(dt->cp_map[i], 'C'))
			ft_msgerr(NOT_PLAY);
		i++;
	}
	ft_free_double_pointer(dt->cp_map);
}
