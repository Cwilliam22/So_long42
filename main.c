#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void    *mlx;        // Pointeur pour MLX
    void    *win;        // Pointeur pour la fenêtre
    int     width = 800; // Largeur de la fenêtre
    int     height = 600; // Hauteur de la fenêtre

    // Initialisation de la MLX
    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Erreur: Impossible d'initialiser la MLX.\n");
        return (EXIT_FAILURE);
    }

    // Création d'une fenêtre
    win = mlx_new_window(mlx, width, height, "Fenêtre So_long");
    if (!win)
    {
        fprintf(stderr, "Erreur: Impossible de créer la fenêtre.\n");
        return (EXIT_FAILURE);
    }

    // Boucle MLX (pour garder la fenêtre ouverte)
    mlx_loop(mlx);

    return (0);
}
