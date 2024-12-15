# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2024/12/15 17:18:14 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Imlx -Ilibft -I. -Isrc

#Chemin vers librairie
MLX = mlx//libmlx.a
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

#Fichiers
SRC =	$(wildcard src/*.c)

# Détection du système d'exploitation
UNAME_S := $(shell uname -s)

# Choix des flags en fonction du système d'exploitation
ifeq ($(UNAME_S),Darwin)
    # macOS
    MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
else
    # Linux
    MLX_FLAGS = -L$(MLX) -lmlx -lXext -lX11
endif

#Objets correspondants
OBJ = $(SRC:.c=.o)

#Commande pour créer la bibliothèque (ar = bi statique)
AR = ar rcs

#Règle par défaut
all: $(NAME)

#Compilation de la bibliothèque
$(NAME): $(OBJ) $(PRINTF) $(MLX) $(LIBFT)
	${CC} ${CFLAGS} ${CI} ${SRC} ${PRINTF} ${LIBFT} ${MLX} ${MLX_FLAGS} -o ${NAME}

#Make Makefile
$(PRINTF):
	make -C printf/

$(MLX):
	make -C mlx/

$(LIBFT):
	make -C libft/

#Compilation des fichiers .o à partir des .c
#($<) => fichier source
#($@) => fichier cible
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

#Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

#Nettoyage complet : fichiers objets + bibliothèque
fclean: clean
	rm -f $(NAME)
	make clean -C printf
	make clean -C libft
	make clean -C mlx

#Reconstruction complète
re: fclean all
