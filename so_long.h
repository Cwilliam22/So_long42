#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_macOS/mlx.h"
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_game {
    void    *mlx; 
    void    *win; 
    int     win_width;
    int     win_height;
}   t_game;

void    init_game(t_game *game, int width, int height);
void    exit_game(t_game *game, const char *message);

#endif
