/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:06:33 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/08 18:47:28 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_textures(t_game *game)
{
	if (!game->sprites)
		return ;
	if (game->sprites->p_face)
		mlx_destroy_image(game->mlx, game->sprites->p_face);
	if (game->sprites->p_back)
		mlx_destroy_image(game->mlx, game->sprites->p_back);
	if (game->sprites->p_side_left)
		mlx_destroy_image(game->mlx, game->sprites->p_side_left);
	if (game->sprites->p_side_right)
		mlx_destroy_image(game->mlx, game->sprites->p_side_right);
	if (game->sprites->wall)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->floor)
		mlx_destroy_image(game->mlx, game->sprites->floor);
	if (game->sprites->coin)
		mlx_destroy_image(game->mlx, game->sprites->coin);
	if (game->sprites->exit)
		mlx_destroy_image(game->mlx, game->sprites->exit);
	if (game->sprites->ennemy)
		mlx_destroy_image(game->mlx, game->sprites->ennemy);
	free(game->sprites);
	game->sprites = NULL;
}

void	free_map(char ***grid)
{
	int	i;

	i = 0;
	if (!grid || !*grid)
		return ;
	while ((*grid)[i])
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);
	*grid = NULL;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->grid)
		free_map(&(game->grid));
	if (game->sprites)
		free_textures(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->grid2)
		free_grid2(game->grid2, game->height);
	free(game);
}

void	free_grid2(char **grid2, int height)
{
	if (!grid2 || height <= 0)
	{
		free(grid2);
		return ;
	}
	free(grid2[height - 1]);
	free_grid2(grid2, height - 1);
}
