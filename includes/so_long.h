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

typedef struct s_game
{
    char **grid;
    int     lenght;
    int     height;
}   t_game;


size_t	ft_condition(char *str);
char	*ft_put_line(char *str);
char	*read_and_store(int fd, char **line);
int	check_null(int fd, char **line);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *s1);
char	*gnl_strchr(const char *str, int a);
char	*gnl_strjoin(char const *s1, char const *s2);

int  map_check1(char *file, t_game *game);
int    count_line(int fd, t_game *game);
int    fill_grid(int fd, int nline, t_game *game);
int check_y(t_game *game);
int wall_check(t_game *game);

int exit_check(t_game *game);

#endif
