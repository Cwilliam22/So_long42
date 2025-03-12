/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:12:54 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/12 20:16:45 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_all(t_game *game)
{
	game->e = 0;
	game->c = 0;
	game->p = 0;
	game->height = 0;
	game->length = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_coin = 0;
	game->player_move = 0;
	game->check_coin = 0;
	game->check_exit = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->file = NULL;
	game->sprites = NULL;
	game->grid2 = NULL;
	game->grid = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: Impossible to init mlx\n"), 0);
	game->window = mlx_new_window(game->mlx, game->length * 125,
			game->height * 125, "so_long");
	if (!game->window)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ft_printf("Error: Impossible to create window\n"), 0);
	}
	if (!load_sprites1(game))
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ft_printf("Error: Failed to load sprites\n"), 0);
	}
	new_image(game);
	return (1);
}

int	check_all(t_game *game, char *file)
{
	if (!map_check(file, game))
		return (ft_printf("Error : check_all1\n"), 0);
	if (!wall_check(game))
		return (ft_printf("Error : check_all2\n"), 0);
	if (!ecp_check(game))
		return (ft_printf("Error : check_all3\n"), 0);
	if (!char_nvalid(game))
		return (ft_printf("Error : check_all4\n"), 0);
	if (!p_player(game))
		return (ft_printf("Error : check_all5\n"), 0);
	if (!flood_check(game))
		return (ft_printf("Error : check_all6\n"), 0);
	return (1);
}

int	look_at_map(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error : look_at_map1\n"), 0);
	if (!count_line(fd, game))
		return (ft_printf("Error : look_at_map2\n"), close(fd), 0);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error : look_at_map3\n"), 0);
	if (!check_all(game, file))
		return (ft_printf("Error : look_at_map4\n"), close(fd), 0);
	close(fd);
	return (1);
}
