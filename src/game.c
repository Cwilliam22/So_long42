#include "../includes/so_long.h"

int    move_player2(t_game *game, int new_x, int new_y)
{
    char next_case;

    if (new_x < 0 || new_y < 0 || new_x >= game->length || new_y >= game->height)
        return (0);
    next_case = game->grid[new_y][new_x];
    if (next_case == '1')
        return (0);
    if (next_case == 'E' && game->player_coin != game->C)
        return (1);
    if (next_case == 'C')
    {
        game->player_coin++;
        game->grid[new_y][new_x] = '0';
    }
    if (game->player_coin == game->C)
        show_exit(game);
    return (1);
}

int move_player1(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;
  
    new_x = game->player_x + dx;
    new_y = game->player_y + dy;
    if (move_player2(game, new_x, new_y))
    {
        game->player_move++;
        ft_printf("Step : %d\n", game->player_move);
    }
    else
        return (0);
    game->grid[game->player_y][game->player_x] = '0';
    game->grid[new_y][new_x] = 'P'; 
    game->player_x = new_x;
    game->player_y = new_y;
    new_image(game);
    if (game->player_coin == game->C)
		mlx_put_image_to_window(game->mlx, game->window, game->sprites->exit,
			game->exit_x * 64, game->exit_y * 64);
    if (game->player_x == game->exit_x && game->player_y == game->exit_y && game->player_coin == game->C)
        win(game);
    return (1);
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
                mlx_put_image_to_window(game->mlx, game->window, 
                    game->sprites->wall, x * 64, y * 64);
            else if (game->grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, 
                    game->sprites->coin, x * 64, y * 64);
            else if (game->grid[y][x] == '0' || game->grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, 
                    game->sprites->floor, x * 64, y * 64);
            x++;
        }
        y++;
    }
    img_front(game);
}


void	win(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_textures(game);
	free_map(&game->grid);
	ft_printf("You win !\n");
	exit(0);
}


