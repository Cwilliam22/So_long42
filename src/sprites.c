/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt <wcapt@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:41:58 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/19 14:38:07 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	load_sprites3(t_game *game)
{
	game->sprites->coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm",
			&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->coin)
		return (free_textures(game),
			ft_printf("Error: Failed to load coin\n"), 0);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->exit)
		return (free_textures(game),
			ft_printf("Error: Failed to load exit\n"), 0);
	game->sprites->enemies = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemies.xpm", &game->sprites->img_width,
			&game->sprites->img_height);
	if (!game->sprites->enemies)
		return (free_textures(game),
			ft_printf("Error: Failed to load enemies\n"), 0);
	return (1);
}

int	load_sprites2(t_game *game)
{
	game->sprites->p_side_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_right.xpm", &game->sprites->img_width,
			&game->sprites->img_height);
	if (!game->sprites->p_side_right)
		return (free_textures(game),
			ft_printf("Error: Failed to load player_right\n"), 0);
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->wall)
		return (free_textures(game),
			ft_printf("Error: Failed to load wall\n"), 0);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->floor)
		return (free_textures(game),
			ft_printf("Error: Failed to load floor\n"), 0);
	if (!load_sprites3(game))
		return (0);
	return (1);
}

int	load_sprites1(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		return (ft_printf("Error: malloc failed sprites\n"), 0);
	game->sprites->p_face = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_front.xpm", &game->sprites->img_width,
			&game->sprites->img_height);
	if (!game->sprites->p_face)
		return (free_textures(game),
			ft_printf("Error: Failed to load player_front\n"), 0);
	game->sprites->p_back = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_back.xpm", &game->sprites->img_width,
			&game->sprites->img_height);
	if (!game->sprites->p_back)
		return (free_textures(game),
			ft_printf("Error: Failed to load player_back\n"), 0);
	game->sprites->p_side_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_left.xpm", &game->sprites->img_width,
			&game->sprites->img_height);
	if (!game->sprites->p_side_left)
		return (free_textures(game),
			ft_printf("Error: Failed to load player_left\n"), 0);
	if (!load_sprites2(game))
		return (0);
	return (1);
}
