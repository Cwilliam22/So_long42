/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:11:43 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/12 18:26:49 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites->p_side_right, game->player_x * 125,
		game->player_y * 125);
}

void	img_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites->p_side_left, game->player_x * 125,
		game->player_y * 125);
}

void	img_front(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites->p_face, game->player_x * 125,
		game->player_y * 125);
}

void	img_back(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites->p_back, game->player_x * 125,
		game->player_y * 125);
}

void	img_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprites->exit, game->exit_x * 125,
		game->exit_y * 125);
}
