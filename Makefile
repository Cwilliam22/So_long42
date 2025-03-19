# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2025/03/12 23:48:19 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = so_long

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0
SL = -Imlx -Imlx_linux -lXext -lX11 -lm -lz
CI = -I ./src/

# Dossiers
SRC_DIR = src
LIBFT_DIR = libft
PRINTF_DIR = printf
MLX_DIR = mlx

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/printf.a
LIBMLX = $(MLX_DIR)/libmlx.a

# Fichiers sources
SRCS =  $(SRC_DIR)/flood_fill.c $(SRC_DIR)/game.c $(SRC_DIR)/get_next_line.c \
        $(SRC_DIR)/img.c $(SRC_DIR)/main.c $(SRC_DIR)/sprites.c \
        $(SRC_DIR)/free.c $(SRC_DIR)/get.c $(SRC_DIR)/get_next_line_utils.c \
        $(SRC_DIR)/init.c $(SRC_DIR)/map_check1.c $(SRC_DIR)/utils.c

# Fichiers objets
OBJ = $(SRCS:.c=.o)

# Dépendances
all: $(LIBFT) $(PRINTF) $(LIBMLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(LIBMLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX)
	@$(CC) $(CFLAGS) $(CI) $(OBJ) $(LIBFT) $(PRINTF) $(LIBMLX) $(SL) -o $(NAME)
	@echo "\033[32m So_long compiled successfully!\033[0m"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[33m Object files removed!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[31m Executable removed!\033[0m"

re: fclean all