
#include "../includes/so_long.h"

int  map_check(char *file, t_game *game)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (ft_printf("map_check1"), 0);
    if (!fill_grid(fd, game->height, game))
        return (ft_printf("map_check2"), close (fd), 0);
    close(fd);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (ft_printf("map_check3"), 0);
    if (!fill_grid2(fd, game->height, game))
        return (ft_printf("map_check4"), close (fd), 0);
    close(fd);

    
    ft_printf("\nDétails des caractères dans game->grid :\n");
    for (int i = 0; i < game->height; i++) 
    {
        if (!game->grid[i]) 
        {
            ft_printf("game->grid[%d] est NULL X \n", i);
        } 
        else 
        {
            ft_printf("game->grid[%d] : ", i);
            for (int j = 0; j < 9; j++) 
            {
                ft_printf("[%c]", game->grid[i][j] ? game->grid[i][j] : '0');
            }
            ft_printf("\n");
        }
    }
    
    if (!count_length(game))
      return (ft_printf("map_check5"), 0);
    return (1);
}

int fill_grid(int fd, int nline, t_game *game)
{
    char *line;
    int i;
    int len;

    i = 0;
    game->grid = (char **)malloc(sizeof(char *) * (nline + 1));
    if (!game->grid)
        return (ft_printf("fill_grid1"), 0);
    while (i < nline)
    {
        line = get_next_line(fd);
        if (!line)
            return (ft_printf("fill_grid2"), 0);
        game->grid[i] = ft_strdup(line);
        if (!game->grid[i])
            return (ft_printf("fill_grid3"), 0);
        len = ft_strlen(game->grid[i]);
        if (len > 0 && game->grid[i][len - 1] == '\n')
            game->grid[i][len - 1] = '\0';
        else
            game->grid[i][len] = '\0';
        ft_printf("game->grid[%d] = \"%s\" (Longueur après correction : %d) \n", i, game->grid[i], ft_strlen(game->grid[i]));
        free(line);
        i++;
    }
    game->grid[i] = NULL; 
    return (1);
}


// (l.61) Si le malloc du ft_strdup échec, alors vérifié game->grid pour vérifié que ft_strdup a bien échoué

int wall_check(t_game *game)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (game->grid[0][j])
    {
        if (game->grid[0][j] != '1')
            return (ft_printf("wall_check1"), 0);
        j++;
    }
    j = 0;
    while (game->grid[game->height - 1][j])
    {
        if (game->grid[game->height - 1][j] != '1')
            return (ft_printf("wall_check2"), 0);
        j++;
    }
    while (i < game->height - 1)
    {
        if (game->grid[i][0] != '1' || game->grid[i][game->length - 1] != '1')
            return (ft_printf("wall_check3"), 0);
        i++;
    }
    return (1);
}

int ECP_check(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->grid[i])
    {
        j = 0;
        while (game->grid[i][j])
        {
            if (game->grid[i][j] == 'E')
                game->E++;
            if (game->grid[i][j] == 'C')
                game->C++;
            if (game->grid[i][j] == 'P')
                game->P++;
            j++;
        }
        i++;
    }
    if (game->E != 1 || game->C < 1 || game->P != 1)
            return (ft_printf("ECP_check"), 0);
    return (1);
}

int char_nvalid(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->grid[i])
    {
        j = 0;
        while (game->grid[i][j])
        {
            if (game->grid[i][j] != 'E' && 
                game->grid[i][j] != 'C' && 
                game->grid[i][j] != 'P' && 
                game->grid[i][j] != '1' && 
                game->grid[i][j] != '0')
                return (ft_printf("char_nvalid"), 0);
            j++;
        }
        i++;
    }
    return (1);
}
