#include "../includes/so_long.h"

int p_player(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->grid[y])
    {
        x = 0;
        while (game->grid[y][x])
        {
            if (game->grid[y][x] == 'P')
            {
                game->player_y = y;
                game->player_x = x;
                game->grid[y][x] = '0';
                if (!show_exit(game))
                    return (0);
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int    show_exit(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->grid[y])
    {
        x = 0;
        while (game->grid[y][x])
        {
            if (game->grid[y][x] == 'E')
            {
                game->exit_y = y;
                game->exit_x = x;
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}
