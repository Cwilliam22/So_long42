# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcapt <wcapt@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 21:34:29 by wcapt             #+#    #+#              #
#    Updated: 2025/01/04 16:49:27 by wcapt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBMLX = mlx/libmlx.a
LIBFT = libft/libft.a
PRINTF = printf/printf.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	$(wildcard src/*.c)

HEAD =	includes/so_long.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc -g -O0
CF = -Wall -Werror -Wextra #-fsanitize=address -static-libasan
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