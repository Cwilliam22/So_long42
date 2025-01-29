#include "../includes/so_long.h"


int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("The number of arguments is incorrect. Try again !!! \n");
		return (ft_printf("main1 \n"), 0);
	}
	init_all(&game);
	//memset(&game, 0);
	if (!look_at_map(&game, argv[1]))
	{
		ft_printf("Error, map invalid. Please use another map. \n");
		// Qqch à free ?
		return (ft_printf("main2 \n"), 0);
	}
	if (!load_textures(&game))
	{
		ft_printf("Error, Failed to load textures. \n");
		free_textures(&game);
		return (ft_printf("main3 \n"), 0);
	}
	if (!init_mlx(&game))
	{
		ft_printf("Error, impossible to init game. \n");
		free_textures(&game);
		return (ft_printf("main4 \n"), 0);
	}
	/*mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_param, NULL);
	mlx_loop(game.mlx);*/
	free_textures(&game);
	return (1);
}