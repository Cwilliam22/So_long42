/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:24:20 by wcapt             #+#    #+#             */
/*   Updated: 2025/03/12 23:41:39 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1000
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_sprites
{
	void	*p_face;
	void	*p_back;
	void	*p_side_left;
	void	*p_side_right;
	void	*wall;
	void	*floor;
	void	*coin;
	void	*exit;
	void	*ennemy;
	int		img_width;
	int		img_height;
}	t_sprites;

typedef struct s_game
{
	char		**grid;
	char		**grid2;
	int			length;
	int			height;
	int			e;
	int			c;
	int			p;
	int			player_coin;
	int			player_move;
	int			check_coin;
	int			check_exit;
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;
	void		*mlx;
	void		*window;
	char		*file;
	t_sprites	*sprites;
}	t_game;

// get_next_line.c
char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*ft_free(char *buffer, char *buf);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);

// get_next_line_utils.c
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *str);
void	free_buffer(char	*buffer);

// map_check1.c
int		map_check(char *file, t_game *game);
int		fill_grid(int fd, int nline, t_game *game);
int		wall_check(t_game *game);
int		ecp_check(t_game *game);
int		char_nvalid(t_game *game);

// init.c
void	init_all(t_game *game);
int		init_mlx(t_game *game);
int		check_all(t_game *game, char *file);
int		look_at_map(t_game *game, char *file);

// flood_fill.c
int		fill_grid2(int fd, int nline, t_game *game);
void	flood_fill(t_game *game, int x, int y);
int		flood_check(t_game *game);

// get.c
void	get_xy(t_game *game);
int		count_line(int fd, t_game *game);
int		count_length(t_game *game);
int		get_keyboard(int keycode, t_game *game);
int		get_exit(t_game *game);

// free.c
void	free_textures(t_game *game);
void	free_map(char ***grid);
void	free_game(t_game *game);
void	free_grid2(char **grid2, int height);

// game.c
int		move_player1(t_game *game, int dx, int dy);
int		move_player2(t_game *game, int new_x, int new_y);
void	new_image(t_game *game);
void	win(t_game *game);

// img.c
void	img_right(t_game *game);
void	img_left(t_game *game);
void	img_front(t_game *game);
void	img_back(t_game *game);
void	img_exit(t_game *game);

// utils.c
int		show_exit(t_game *game);
int		p_player(t_game *game);

// sprites.c
int		load_sprites1(t_game *game);
int		load_sprites2(t_game *game);
int		load_sprites3(t_game *game);
#endif
