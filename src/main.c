/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamcapt <williamcapt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:57:42 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/12 19:14:12 by williamcapt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error : Memory allocation failed\n"), 1);
	if (argc != 2)
		return (ft_printf("Error : Nbr arguments is wrong\n"), free(game), 0);
	init_all(game);
	if (!look_at_map(game, argv[1]))
	{
		ft_printf("Error : map invalid. Please use another map. \n");
		free_map(&(game->grid));
		return (free(game), 0);
	}
	if (!init_mlx(game))
	{
		ft_printf("Error : impossible to init game. \n");
		free_map(&(game->grid));
		free_textures(game);
		return (free(game), 0);
	}
	mlx_hook(game->window, 2, 1L << 0, get_keyboard, game);
	mlx_hook(game->window, 17, 0, get_exit, game);
	mlx_loop(game->mlx);
	return (free_game(game), 0);
}
