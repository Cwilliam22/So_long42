#include "../includes/so_long.h"

void free_textures(t_game *game)
{
	if (!game->sprites)
		return ;
	if (game->sprites->p_face)
		mlx_destroy_image(game->mlx, game->sprites->p_face);
	if (game->sprites->p_back)
		mlx_destroy_image(game->mlx, game->sprites->p_back);
	if (game->sprites->p_side_left)
		mlx_destroy_image(game->mlx, game->sprites->p_side_left);
	if (game->sprites->p_side_right)
		mlx_destroy_image(game->mlx, game->sprites->p_side_right);
	if (game->sprites->wall)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->floor)
		mlx_destroy_image(game->mlx, game->sprites->floor);
	if (game->sprites->coin)
		mlx_destroy_image(game->mlx, game->sprites->coin);
	if (game->sprites->exit)
		mlx_destroy_image(game->mlx, game->sprites->exit);
	if (game->sprites->ennemy)
		mlx_destroy_image(game->mlx, game->sprites->ennemy);
	free(game->sprites);
	game->sprites = NULL;
}


void free_map(char ***grid)
{
    int i = 0;

    if (!grid || !*grid)
        return;

    while ((*grid)[i])
    {
        free((*grid)[i]);
        i++;
    }
    free(*grid);
    *grid = NULL;
}
