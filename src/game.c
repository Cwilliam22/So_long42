#include "../includes/so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;
    char next_case;

    new_x = game->player_x + dx;
    new_y = game->player_y + dy;
    if (new_x < 0 || new_y < 0 || new_x >= game->length || new_y >= game->height)
        return;
    next_case = game->grid[new_y][new_x];
    if (next_case == '1')
        return;
    if (next_case == 'C')
    {
        game->player_coin++;
        game->grid[new_y][new_x] = '0';
    }
    if (next_case == 'E' && game->player_coin == game->C)
    {
        ft_printf("Bravo, vous avez gagné en %d déplacements !\n", game->player_coin);
        get_exit(game);
    }
    game->grid[game->player_y][game->player_x] = '0';
    game->grid[new_y][new_x] = 'P'; 
    game->player_x = new_x;
    game->player_y = new_y;
    game->player_coin++;
    ft_printf("Déplacements : %d\n", game->player_coin);
    new_image(game);
}

void new_image(t_game *game)
{
    int x; 
    int y;

    mlx_clear_window(game->mlx, game->window);
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->length)
        {
            if (game->grid[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites->wall, x * 32, y * 32);
            else if (game->grid[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites->floor, x * 32, y * 32);
            else if (game->grid[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites->p_face, x * 32, y * 32);
            else if (game->grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites->coin, x * 32, y * 32);
            else if (game->grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->sprites->exit, x * 32, y * 32);
            x++;
        }
        y++;
    }
}

