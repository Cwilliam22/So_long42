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
		ft_printf("Impossible to init mlx\n");
		return (ft_printf("init_mlx1"), 0);
	}
    game->window = mlx_new_window(game->mlx, game->length * 64, 
    game->height * 64 + 32, "so_long");
    if (!game->window)
    {
        ft_printf("Impossible to creat window\n");
        return (ft_printf("init_mlx2"), 0);
    }
    game->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		ft_printf("Impossible to create sprites\n");
		return (ft_printf("init_mlx3"), 0);
	}
	load_textures(game);
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

int load_textures(t_game *game)
{
    game->sprites->p_face = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->sprites->img_width, &game->sprites->img_height);
	game->sprites->p_back = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->sprites->img_width, &game->sprites->img_height);
    if (!game->sprites->p_face || !game->sprites->p_back)
		return (free_textures(game), ft_printf("load_textures1"), 0);
    game->sprites->p_side_left = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->sprites->img_width, &game->sprites->img_height);
	game->sprites->p_side_right = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &game->sprites->img_width, &game->sprites->img_height);
    if (!game->sprites->p_side_left || !game->sprites->p_side_right)
		return (free_textures(game), ft_printf("load_textures2"), 0);
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &game->sprites->img_width, &game->sprites->img_height);
	game->sprites->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &game->sprites->img_width, &game->sprites->img_height);
    if (!game->sprites->wall || !game->sprites->floor)
		return (free_textures(game), ft_printf("load_textures3"), 0);
	game->sprites->coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &game->sprites->img_width, &game->sprites->img_height);
	game->sprites->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &game->sprites->img_width, &game->sprites->img_height);
    if (!game->sprites->coin || !game->sprites->exit)
		return (free_textures(game), ft_printf("load_textures4"), 0);
    return (1);
}
