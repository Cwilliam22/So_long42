#include "../includes/so_long.h"

int    fill_grid2(int fd, int nline, t_game *game)
{
    char *line;
    int i;
    int len;

    i = 0;
    game->grid2 = (char **)malloc(sizeof(char *) * (nline + 1));
    if (!game->grid2)
        return (ft_printf("fill_grid21"), 0);
    while (i < nline)
    {
        line = get_next_line(fd);
        if (!line)
            return (ft_printf("fill_grid22"), free_map(&game->grid2), 0);
        game->grid2[i] = ft_strdup(line);
        free(line);
        if (!game->grid2[i])
            return (ft_printf("fill_grid23"), free_map(&game->grid2), 0);
// Si le malloc du ft_strdup échec, alors vérifié game->grid pour vérifié que ft_strdup a bien échoué
        len = ft_strlen(game->grid2[i]);
        if (len > 0 && game->grid2[i][len - 1] == '\n')
            game->grid2[i][len - 1] = '\0';
        else
            game->grid2[i][len] = '\0';
        i++;
    }
    game->grid2[i] = NULL; 
    return (1);
}


////////////////////////////////////////////////////////
void print_grid2(t_game *game)
{
    int y = 0;

    if (!game->grid2)
    {
        ft_printf("Error: grid2 is not allocated\n");
        return;
    }

    ft_printf("\n--- GRID2 STATE ---\n");
    while (y < game->height)
    {
        ft_printf("%s\n", game->grid2[y]);
        y++;
    }
    ft_printf("--------------------\n");
}
////////////////////////////////////////////////////////



void flood_fill(t_game *game, int x, int y)
{
    if (x <= 0 || y <= 0 || x >= game->length || y >= game->height)
        return;
    if (game->grid2[y][x] == '1' || game->grid2[y][x] == 'V')
        return;
    if (game->grid2[y][x] == '0' || game->grid2[y][x] == 'P')
        game->grid2[y][x] = 'V';
    if (game->grid2[y][x] == 'C')
    {
        game->grid2[y][x] = 'V';
        game->check_coin++;
    }
    if (game->grid2[y][x] == 'E')
    {
        game->grid2[y][x] = 'V';
        game->check_exit++;
        return;
    }
    flood_fill(game, x + 1, y);
    flood_fill(game, x - 1, y);
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
}


int flood_check(t_game *game)
{
    get_xy(game);
    flood_fill(game, game->player_x, game->player_y);
	if (game->C != game->check_coin || game->check_exit != 1)
	{
		free_map(&game->grid2);
        printf("C : %d\n", game->C);
        printf("check_coin : %d\n", game->check_coin);
        printf("exit3 : %d\n", game->check_exit);
        if (game->C != game->check_coin)
            ft_printf("Error: Not all collectibles are accessible\n");
        if (game->check_exit != 1)
            ft_printf("Error: The exit is not accessible\n");
		return (ft_printf("flood_check\n"), 0);
	}
    return (1);
}
