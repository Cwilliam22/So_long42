/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:14:44 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/12 23:40:40 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_check(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error : map_check1 fails"), 0);
	if (!fill_grid(fd, game->height, game))
		return (ft_printf("Error : map_check2 fails"), close (fd), 0);
	if (!count_length(game))
		return (ft_printf("Error : map_check3 fails"), 0);
	close(fd);
	get_next_line(-42);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error : map_check4 fails"), 0);
	if (!fill_grid2(fd, game->height, game))
		return (ft_printf("Error : map_check5 fails"), close (fd), 0);
	close(fd);
	get_next_line(-42);
	return (1);
}

int	wall_check(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (game->grid[0][j])
	{
		if (game->grid[0][j] != '1')
			return (ft_printf("wall_check1 fails"), free_map(&game->grid2), 0);
		j++;
	}
	j = 0;
	while (game->grid[game->height - 1][j])
	{
		if (game->grid[game->height - 1][j] != '1')
			return (ft_printf("wall_check2 fails"), free_map(&game->grid2), 0);
		j++;
	}
	while (i < game->height - 1)
	{
		if (game->grid[i][0] != '1' || game->grid[i][game->length - 1] != '1')
			return (ft_printf("wall_check3 fails"), free_map(&game->grid2), 0);
		i++;
	}
	return (1);
}

int	ecp_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'E')
				game->e++;
			if (game->grid[i][j] == 'C')
				game->c++;
			if (game->grid[i][j] == 'P')
				game->p++;
			j++;
		}
		i++;
	}
	if (game->e != 1 || game->c < 1 || game->p != 1)
		return (ft_printf("Error : ecp_check fails"),
			free_map(&game->grid2), 0);
	return (1);
}

int	char_nvalid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] != 'E' &&
				game->grid[i][j] != 'C' &&
				game->grid[i][j] != 'P' &&
				game->grid[i][j] != '1' &&
				game->grid[i][j] != '0')
				return (ft_printf("Error : char_nvalid fails"),
					free_map(&game->grid2), 0);
			j++;
		}
		i++;
	}
	return (1);
}
