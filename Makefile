# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 08:50:48 by blevrel           #+#    #+#              #
#    Updated: 2023/02/10 20:14:26 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	cub3D

SRCS  =	srcs/cub3d.c \
		srcs/open_window.c	\
		srcs/launch_game.c	\
		srcs/parsing/check_valid_scene.c \
		srcs/parsing/fill_matrix.c \
		srcs/parsing/check_map_content.c \
		srcs/parsing/init_struc.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/init_textures_and_colors.c \
		srcs/parsing/free_struc_elements.c	\
		srcs/parsing/get_elements.c	\
		srcs/movement_management/move.c	\
		srcs/movement_management/movement_management.c	\

OBJS  =	${SRCS:.c=.o}

CC	  =	clang

CFLAGS = -Wall -Wextra -Werror

LIB   =	-L. -Lmlx_linux -Llibft -lmlx -lft -lXext -lX11 -lm

HEAD  =	-I mlx_linux -I libft -I includes

RM	  =	rm -f

all: ${NAME}

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.c.o:
	${CC} ${CFLAGS} -c ${HEAD} $< -o ${<:.c=.o} -g

${NAME}: ${OBJS}
	make -C libft
	make -C mlx_linux
	${CC} ${CFLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME} -g

.PHONY: all re clean fclean bonus
