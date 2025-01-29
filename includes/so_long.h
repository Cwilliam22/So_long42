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
# include <unistd.h>

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
	void	*lava;
    int     img_width;
    int     img_height;
}	t_sprites;

typedef struct s_game
{
    char        **grid;
    char        **grid2;
    int         length;
    int         height;
    int         E;
    int         C;
    int         P;
    int         player_coin;
    int         check_coin;
    int         check_exit;
    int         player_x;
    int         player_y;
    void        *mlx;
    void        *window;
    char        *file;
    t_sprites   *sprites;
    
}   t_game;

// L'ordre des structures est-il important ??

char	*get_next_line(int fd);
char	*read_file(int fd, char *res);
char	*ft_free(char *buffer, char *buf);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strchr(const char *str, int c);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *str);

int     map_check(char *file, t_game *game);
int     fill_grid(int fd, int nline, t_game *game);
int     wall_check(t_game *game);
int     ECP_check(t_game *game);
int     char_nvalid(t_game *game);

void    init_all(t_game *game);
int     init_mlx(t_game *game);
int     check_all(t_game *game, char *file);
int     look_at_map(t_game *game, char *file);
int     load_textures(t_game *game);

int     fill_grid2(int fd, int nline, t_game *game);
void    flood_fill(t_game *game, int x, int y);
int     flood_check(t_game *game);

void    get_xy(t_game *game);
int     count_line(int fd, t_game *game);
int     count_length(t_game *game);

void    free_textures(t_game *game);
void    free_grid(char **grid);
#endif