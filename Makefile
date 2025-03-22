# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2025/03/22 13:41:40 by wcapt            ###   ########.fr        #
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
	@echo "\033[32m ░▒▓███████▓▒░░▒▓██████▓▒░░▒▓█▓▒░      ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░  \033[0m"
	@echo "\033[32m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \033[0m"
	@echo "\033[32m░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        \033[0m"
	@echo "\033[32m ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░ \033[0m"
	@echo "\033[32m       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \033[0m"
	@echo "\033[32m       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ \033[0m"
	@echo "\033[32m░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  \033[0m"
	@echo "\033[32m                                                                               \033[0m"
	@echo "\033[32m  ██████  ▒█████   ██▓     ▒█████   ███▄    █   ▄████                          \033[0m"
	@echo "\033[32m▒██    ▒ ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒                         \033[0m"
	@echo "\033[32m░ ▓██▄   ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░                         \033[0m"
	@echo "\033[32m  ▒   ██▒▒██   ██░▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓                         \033[0m"
	@echo "\033[32m▒██████▒▒░ ████▓▒░░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒                         \033[0m"
	@echo "\033[32m▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒                          \033[0m"
	@echo "\033[32m░ ░▒  ░ ░  ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░                          \033[0m"
	@echo "\033[32m░  ░  ░  ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░                          \033[0m"
	@echo "\033[32m      ░      ░ ░      ░  ░    ░ ░           ░       ░                          \033[0m"
	@echo "\033[32m ____                    __                                                    \033[0m"
	@echo "\033[32m/\  _`\                 /\ \                                                   \033[0m"
	@echo "\033[32m\ \,\L\_\    ___        \ \ \        ___     ___      __                       \033[0m"
	@echo "\033[32m \/_\__ \   / __`\       \ \ \  __  / __`\ /' _ `\  /'_ `\                     \033[0m"
	@echo "\033[32m   /\ \L\ \/\ \L\ \       \ \ \L\ \/\ \L\ \/\ \/\ \/\ \L\ \                    \033[0m"
	@echo "\033[32m   \ `\____\ \____/        \ \____/\ \____/\ \_\ \_\ \____ \                   \033[0m"
	@echo "\033[32m    \/_____/\/___/   _______\/___/  \/___/  \/_/\/_/\/___L\ \                  \033[0m"
	@echo "\033[32m                    /\______\                         /\____/                  \033[0m"
	@echo "\033[32m                    \/______/                         \_/__/                   \033[0m"
	@echo "\033[32m                                                                               \033[0m"
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