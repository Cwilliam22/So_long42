#include "../includes/so_long.h"

int exit_check(t_game *game)
{
    int i;
    int j;
    int a;

    i = 0;
    a = 0;
    while (game->grid[i][j])
    {
        j = 0;
        while (game->grid[i][j])
        {
            if (game->grid[i][j] == 'E')
                a++;
            j++;
        }
        i++;
        if (a != 1)
            return (0);
    }
    return (1);
}


int coin_check(t_game *gamessh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIEo1/M3+TzZR48BSMeeK0fjn7gtBD/ueYBvoSFl+K3Sd williamcapt@williamcapt
)
{
    int i;
    int j;
    int a;

    i = 0;
    a = 0;
    while (game->grid[i][j])
    {
        j = 0;
        while (game->grid[i][j])
        {
            if (game->grid[i][j] == 'E')
                a++;
            j++;
        }
        i++;
        if (a < 1)
            return (0);
    }
    return (1);
}


