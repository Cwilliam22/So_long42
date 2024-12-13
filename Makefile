# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2024/12/12 21:45:04 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = So_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Détection du système d'exploitation
UNAME_S := $(shell uname -s)

#Chemin vers MLX
MLX_WAY = mlx

# Choix des flags en fonction du système
ifeq ($(UNAME_S),Darwin)
    # macOS
    MLX_FLAGS = -L$(MLX_WAY) -lmlx -framework OpenGL -framework AppKit
else
    # Linux
    MLX_FLAGS = -L$(MLX_WAY) -lmlx -lXext -lX11
endif

#Fichiers
SRC =	SRC = main.c utils.c map.c

#Objets correspondants
OBJ = $(SRC:.c=.o)

#Commande pour créer la bibliothèque (ar = bi statique)
AR = ar rcs

#Règle par défaut
all: $(NAME)

#Compilation de la bibliothèque (pour construire libft.a)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

#Compilation des fichiers .o à partir des .c
#($<) => fichier source
#($@) => fichier cible
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

#Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

#Nettoyage complet : fichiers objets + bibliothèque
fclean: clean
	rm -f $(NAME)

#Reconstruction complète
re: fclean all
