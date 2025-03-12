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

NAME = so_long
LIBMLX = mlx/libmlx.a
LIBFT = libft/libft.a
PRINTF = printf/printf.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////
SRC_DIR = src
SRCS =	$(SRC_DIR)/flood_fill.c $(SRC_DIR)/game.c $(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/img.c $(SRC_DIR)/main.c $(SRC_DIR)/sprites.c \
		$(SRC_DIR)/free.c $(SRC_DIR)/get.c $(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/init.c $(SRC_DIR)/map_check1.c $(SRC_DIR)/utils.c

HEAD =	includes/so_long.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc -g -O0
CF = -Wall -Werror -Wextra 
SL = -Imlx -Imlx_linux -lXext -lX11 -lm -lz
CI = -I ./src/


AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${SRCS} ${HEAD} ${PRINTF} ${LIBFT} ${LIBMLX}
	${CC} ${CF} ${CI} ${SRCS} ${PRINTF} ${LIBFT} ${LIBMLX} ${SL} -o ${NAME}

${PRINTF}:
	make -C printf/

${LIBMLX}:
	make -C mlx/

${LIBFT}:
	make -C libft/

# Mandatory rules

clean:
	${RM} mlx/*.o mlx/test/*.o src/*.o libft/*.o

fclean: clean
	${RM} ${NAME}
	make clean -C mlx
	make clean -C libft
	make fclean -C printf

re: fclean all
