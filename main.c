#include "so_long.h"

int close_window(t_game *game)
{
    exit_game(game, "Fenêtre fermée proprement.");
    return (0);
}

int main(void)
{
    t_game game;

    init_game(&game, 800, 600);
    mlx_hook(game.win, 17, 0, close_window, &game);

    mlx_loop(game.mlx);
    return (0);
}
