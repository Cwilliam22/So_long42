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
            return (ft_printf("fill_grid22"), 0);
        game->grid2[i] = ft_strdup(line);
        if (!game->grid2[i])
            return (ft_printf("fill_grid23"), 0);
// Si le malloc du ft_strdup échec, alors vérifié game->grid pour vérifié que ft_strdup a bien échoué
        len = ft_strlen(game->grid2[i]);
        if (len > 0 && game->grid2[i][len - 1] == '\n')
            game->grid2[i][len - 1] = '\0';
        free(line);
        i++;
    }
    game->grid2[i] = NULL; 
    return (1);
}

void flood_fill(t_game *game, int x, int y)
{
    if ((game->grid2[x][y] = '0'))
        game->grid2[x][y] = 'V';
    if ((game->grid2[x][y] = 'P'))
        game->grid2[x][y] = '0';
    if ((game->grid2[x][y] = 'C'))
    {
        game->grid2[x][y] = '0';
        game->check_coin++;
    }
    if ((game->grid2[y][x] == 'E'))
		game->check_exit++;
    if ((game->grid2[y][x] != '0'
		&& game->grid2[y][x] != 'E' && game->grid2[y][x] != 'C'
		&& game->grid2[y][x] != 'P') || x < 0 || y < 0)
		return ;
    flood_fill(game, x + 1, y);
    flood_fill(game, x - 1, y);    
    flood_fill(game, x, y + 1);
    flood_fill(game, x, y - 1);
}

int flood_check(t_game *game)
{
    flood_fill(game, game->player_x, game->player_y);
	if (game->C != game->check_coin || game->check_exit == 0)
	{
		free_grid(game->grid2);
		return (ft_printf("flood_check"), 0);
	}
    return (1);
}
