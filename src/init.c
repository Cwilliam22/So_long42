#include "../includes/so_long.h"

void init_all(t_game *game)
{
	game->E = 0;
	game->C = 0;
	game->P = 0;
	game->height = 0;
	game->length = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_coin = 0;
	game->check_coin = 0;
	game->check_exit = 0;
	game->grid2 = NULL;
	game->grid = NULL;
	game->mlx = NULL;
	game->window = NULL;
}

int init_mlx(t_game *game)
{
    game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Impossible to init mlx\n");
		return (0);
	}
    game->window = mlx_new_window(game->mlx, game->length * 64, game->height * 64 + 32, "so_long");
    if (!game->window)
    {
        ft_printf("Error: Impossible to create window\n");
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (0);
    }
    if (!load_textures(game))
    {
        ft_printf("Error: Failed to load textures\n");
        mlx_destroy_window(game->mlx, game->window);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (0);
    }
    return (1);
}


int	check_all(t_game *game, char *file)
{
	if (!map_check(file, game))
		return (ft_printf("check_all1"), 0);
	if (!wall_check(game))
		return (ft_printf("check_all2"), 0);
	if (!flood_check(game))
		return (ft_printf("check_all3"), 0);
    if (!ECP_check(game))
        return (ft_printf("check_all4"), 0);
    if (!char_nvalid(game))
		return (ft_printf("check_all5"), 0);
	return (1);
}

int look_at_map(t_game *game, char *file)
{
    int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
        return (ft_printf("look_at_map1\n"), 0);
    if (!count_line(fd, game))
        return (ft_printf("look_at_map2\n"), close(fd), 0);
    close(fd);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (ft_printf("look_at_map3\n"), 0);
    if (!check_all(game, file))
        return (ft_printf("look_at_map4\n"), close(fd), 0);
    close(fd);
    return (1);
}

int	load_textures(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		return (ft_printf("Error: malloc failed for sprites\n"), 0);
	game->sprites->p_face = mlx_xpm_file_to_image(game->mlx, "sprites/player_front.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->p_face)
		return (free_textures(game), ft_printf("Error: Failed to load player_front\n"), 0);
	game->sprites->p_back = mlx_xpm_file_to_image(game->mlx, "sprites/player_back.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->p_back)
		return (free_textures(game), ft_printf("Error: Failed to load player_back\n"), 0);
	game->sprites->p_side_left = mlx_xpm_file_to_image(game->mlx, "sprites/player_left.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->p_side_left)
		return (free_textures(game), ft_printf("Error: Failed to load player_left\n"), 0);
	game->sprites->p_side_right = mlx_xpm_file_to_image(game->mlx, "sprites/player_right.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->p_side_right)
		return (free_textures(game), ft_printf("Error: Failed to load player_right\n"), 0);
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->wall)
		return (free_textures(game), ft_printf("Error: Failed to load wall\n"), 0);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->floor)
		return (free_textures(game), ft_printf("Error: Failed to load floor\n"), 0);
	game->sprites->coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->coin)
		return (free_textures(game), ft_printf("Error: Failed to load coin\n"), 0);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->exit)
		return (free_textures(game), ft_printf("Error: Failed to load exit\n"), 0);
	game->sprites->ennemy = mlx_xpm_file_to_image(game->mlx, "sprites/lava.xpm",
		&game->sprites->img_width, &game->sprites->img_height);
	if (!game->sprites->ennemy)
		return (free_textures(game), ft_printf("Error: Failed to load ennemy\n"), 0);
	return (1);
}
