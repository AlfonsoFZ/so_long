/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:27:15 by alfofern          #+#    #+#             */
/*   Updated: 2023/05/31 19:55:33 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

char	*ft_strjoinandfree(char *s1, char *s2, t_dt *dt)
{
	char		*dest;
	size_t		i;
	size_t		j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	dest = (char *)ft_calloc(((ft_strlen(s1) + ft_strlen(s2) + 1)), 1);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
			dest[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	if (dt->i > 0)
		free(s1);
	dt->i++;
	return (dest);
}

void	ft_read(t_dt *dt)
{
	char	*line;
	char	*read;

	read = "";
	line = "";
	while (1)
	{
		line = get_next_line(dt->mapfd);
		if (line == 0)
			break ;
		read = ft_strjoinandfree(read, line, dt);
		free(line);
	}
	if (read == 0 || read[0] == '\n')
	{	
		free(read);
		ft_msgerr("Empty map or empty line at the beginning of the map\n");
	}
	ft_chkemptyline(read);
	dt->rmap = ft_split(read, '\n');
	dt->cp_map = ft_split(read, '\n');
	free(read);
	close(dt->mapfd);
}

void	ft_check_map(t_dt *dt, char *map)
{
	dt->mapfile = ft_checkfile(map);
	dt->mapfd = open(dt->mapfile, O_RDONLY);
	dt->i = 0;
	if (dt->mapfd == -1)
		ft_msgerr(OPEN_ERR);
	else
		ft_read(dt);
	ft_initdt(dt);
	ft_chkshape(dt);
	ft_chkpath(dt);
}

// void    ft_leaks(void)
// {
//     system("leaks so_long");
// }
// include this sentence into the main function: atexit(ft_leaks);

int	main(int argc, char *argv[])
{
	t_dt	dt;

	if (argc == 2)
	{
		ft_check_map(&dt, argv[1]);
		ft_startthegame(&dt);
		ft_free_dt(&dt);
		return (EXIT_SUCCESS);
	}
	ft_msgerr(WRONG_ARG);
	return (EXIT_FAILURE);
}
