# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 08:50:48 by blevrel           #+#    #+#              #
#    Updated: 2023/02/12 07:44:04 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	cub3D

SRCS  =	srcs/cub3d.c \
		srcs/launch_game.c	\
		srcs/open_window.c	\
		srcs/display_minimap.c	\
		srcs/my_pixel_put.c	\
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
		srcs/movement_management/check_collision.c	\
		

OBJS  =	${SRCS:.c=.o}

CC	  =	clang

CFLAGS =	-Wall -Wextra -Werror

LIB   =	-L mlx_linux -lmlx -lXext -lX11 -lm -L libft -lft

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

%.o: %.c includes/cub3d.h
	${CC} ${CFLAGS} -c ${HEAD} $< -o ${<:.c=.o} -g

${NAME}: ${OBJS}
	make -C libft
	make -C mlx_linux
	${CC} ${CFLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME} -g

.PHONY: all re clean fclean bonus
