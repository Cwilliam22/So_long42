#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("The number of arguments is incorrect. Try again !!! \n");
		return (0);
	}
	// Initialisation de la structure à zéro
	init_all(&game);
	// Vérification de la map
	if (!look_at_map(&game, argv[1]))
	{
		ft_printf("Error, map invalid. Please use another map. \n");
		free_map(&game.grid); // Libère la mémoire si la map a été allouée
		return (0);
	}
	// Initialisation de MLX et création de la fenêtre
	if (!init_mlx(&game))
	{
		ft_printf("Error, impossible to init game. \n");
		free_map(&game.grid);
		free_textures(&game);
		return (0);
	}
	// Ajout des hooks pour gérer les touches et la fermeture du jeu
	mlx_hook(game.window, 2, 1L << 0, get_keyboard, &game);
	mlx_hook(game.window, 17, 0, get_exit, &game);
	// Lancement de la boucle MLX
	mlx_loop(game.mlx);
	// Libération de la mémoire (normalement jamais atteint)
	free_map(&game.grid);
	free_textures(&game);
	return (0);
}
