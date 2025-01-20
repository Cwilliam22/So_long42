
#include "../includes/so_long.h"

int  map_check1(char *file, t_game *game)
{
    int fd;
    int line;

    line = 0;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    line = game->height;
    if (line <= 2)
        return (0);
    close(fd);
    fd = open(file, O_RDONLY);
    fill_grid(fd, line, game);
    return (1);
}


int    count_line(int fd, t_game *game)
{
    char *line;
    int     count;

    count = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        count++;
        free(line);
    }
    if (count <= 2)
        return (0); // Cette condition existe 2x (ici et dans la fonction check_map)
    game->height = count;
    return (1);
}


int    fill_grid(int fd, int nline, t_game *game)
{
    char *line;
    int     count;
    int     i;

    i = 0;
    count = nline;
    game->grid = (char **)malloc(sizeof(char *) * (nline + 1));
    if (!game->grid)
        return (0);
    while (i < count)
    {
        line = get_next_line(fd);
        game->grid[i] = ft_strdup(line);
        if (!game->grid[i])
            return (0);
// Si le malloc du ft_strdup échec, alors vérifié game->grid pour vérifié que ft_strdup a bien échoué
        i++;
        free(line);
    }
    return (1);
}

int check_y(t_game *game)
{
    int len_line1;
    int x;

    len_line1 = ft_strlen(game->grid[0]);
    x = 1;
    while (game->grid[x])
    {
        if (ft_strlen(game->grid[x]) != len_line1)
            return (0);
        x++;
    }
    game->lenght = len_line1; 
    return (1);
}

int wall_check(t_game *game)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (game->grid[0][j])
    {
        if (game->grid[0][j] != '1')
            return (0);
        j++;
    }
    j = 0;
    while (game->grid[game->height - 1][j])
    {
        if (game->grid[game->height - 1][j] != '1')
            return (0);
        j++;
    }
    while (i < game->height - 1)
    {
        if (game->grid[i][0] != '1' || game->grid[i][game->lenght - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "so_long.h"
#include <unistd.h>

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        printf("Erreur: Nombre d'arguments invalide.\n");
    else
        printf(map_check1(argv[1], &game));
    return (0);
}
*/


// gcc -Wall -Wextra -Werror -o map_check.c
// ./so_long map.ber

