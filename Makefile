# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2024/12/15 19:09:11 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION
INCLUDES = -Imlx -Ilibft -I. -Isrc

#Détection du système d'exploitation
UNAME_S := $(shell uname -s)

#Chemins vers librairies
#Choix du dos selon l'OS
ifeq ($(UNAME_S),Darwin)
	MLX_DIR = mlx_macOS
else
	MLX_DIR = mlx_linux
endif
LIBFT_DIR = libft
PRINTF_DIR = printf

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

#Fichiers sources et objets
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

#Choix des flags selon l'OS
ifeq ($(UNAME_S),Darwin)
    #MacOS
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    #Linux
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
endif

#Règle par défaut
all: $(NAME)

#Compilation de l'exécutable
$(NAME): $(OBJ) $(PRINTF) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

#Compilation des bibliothèques
$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

#Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

#Nettoyage des fichiers objets
clean:
	rm -f $(OBJ) $(DEP)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

#Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

#Reconstruction complète
re: fclean all


