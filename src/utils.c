/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:38:44 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/19 14:41:59 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	p_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				game->grid[y][x] = '0';
				if (!show_exit(game))
					return (0);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	show_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'E')
			{
				game->exit_y = y;
				game->exit_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	fill_grid(int fd, int nline, t_game *game)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	game->grid = (char **)malloc(sizeof(char *) * (nline + 1));
	if (!game->grid)
		return (ft_printf("fill_grid1"), 0);
	while (i < nline)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_printf("fill_grid2"), free_map(&game->grid), 0);
		game->grid[i] = ft_strdup(line);
		free(line);
		if (!game->grid[i])
			return (ft_printf("fill_grid3"), free_map(&game->grid), 0);
		len = ft_strlen(game->grid[i]);
		if (len > 0 && game->grid[i][len - 1] == '\n')
			game->grid[i][len - 1] = '\0';
		else
			game->grid[i][len] = '\0';
		i++;
	}
	return (line = get_next_line(fd), free (line), game->grid[i] = NULL, 1);
}

void	lose(t_game *game)
{
	free_game(game);
	ft_printf("You lose !\n");
	exit(0);
}

void	line_to_long(t_game *game, int x, int y)
{
	if (game->grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->wall, x * 125, y * 125);
	else if (game->grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->coin, x * 125, y * 125);
	else if (game->grid[y][x] == 'B')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->enemies, x * 125, y * 125);
	else if (game->grid[y][x] == '0' || game->grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprites->floor, x * 125, y * 125);
}
