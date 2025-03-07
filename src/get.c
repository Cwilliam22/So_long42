/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:10:03 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/07 13:26:14 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_xy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->grid[i])
	{
		j = 0;
		while (game->grid[i][j])
		{
			if (game->grid[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

int	count_line(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count <= 2)
		return (ft_printf("Error : The number of lines is wrong\n"), 0);
	game->height = count;
	return (1);
}

int	count_length(t_game *game)
{
	int	len_line1;
	int	x;

	len_line1 = ft_strlen(game->grid[0]);
	x = 1;
	if (len_line1 <= 2)
		return (ft_printf("Error : The length of lines is wrong\n"), 0);
	while (game->grid[x])
	{
		if (ft_strlen(game->grid[x]) != len_line1)
			return (ft_printf("Error : The lines aren't the same length\n"), 0);
		x++;
	}
	game->length = len_line1;
	return (1);
}

int	get_keyboard(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		get_exit(game);
	if (keycode == KEY_W)
	{
		move_player1(game, 0, -1);
		img_back(game);
	}
	else if (keycode == KEY_S)
	{
		move_player1(game, 0, 1);
		img_front(game);
	}
	else if (keycode == KEY_A)
	{
		move_player1(game, -1, 0);
		img_left(game);
	}
	else if (keycode == KEY_D)
	{
		move_player1(game, 1, 0);
		img_right(game);
	}
	return (0);
}

int	get_exit(t_game *game)
{
	free_game(game);
	ft_printf("Game close !\n");
	exit(0);
	return (0);
}
