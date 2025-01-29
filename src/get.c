#include "../includes/so_long.h"

void get_xy(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->grid[i])
    {
        j = 0;
        while (game->grid[i][j])
        {
            if (game->grid[i][j] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
            }
            j++;
        }
        i++;
    }
}

int    count_line(int fd, t_game *game)
{
    char *line;
    int     count;

    count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        count++;
        free(line);
    }
    if (count <= 2)
        return (0);
    game->height = count;
    return (1);
}

int count_length(t_game *game)
{
    int len_line1;
    int x;

    len_line1 = ft_strlen(game->grid[0]);
    x = 1;
    if (len_line1 <= 2)
        return (0);
    while (game->grid[x])
    {
        if (ft_strlen(game->grid[x]) != len_line1)
            return (0);
        x++;
    }
    game->length = len_line1; 
    return (1);
}
