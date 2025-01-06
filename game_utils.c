#include "so_long.h"


void init_game(t_game *game, int width, int height)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_printf("Erreur : Impossible d'initialiser MiniLibX.\n");
        exit(EXIT_FAILURE);
    }
    game->win_width = width;
    game->win_height = height;
    game->win = mlx_new_window(game->mlx, width, height, "So_long - Jeu");
    if (!game->win)
    {
        ft_printf("Erreur : Impossible de créer la fenêtre.\n");
        exit(EXIT_FAILURE);
    }
    ft_printf("Fenêtre de %dx%d pixels créée avec succès.\n", width, height);
}

void exit_game(t_game *game, const char *message)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    ft_printf("%s\n", message);
    exit(EXIT_SUCCESS);
}
