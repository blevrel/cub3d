# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blevrel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 08:50:48 by blevrel           #+#    #+#              #
#    Updated: 2023/02/07 14:32:24 by blevrel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	cub3D

SRCS  =	srcs/cub3d.c \
		srcs/parsing/check_valid_scene.c \
		srcs/parsing/fill_matrix.c \
		srcs/parsing/check_map_content.c \
		srcs/parsing/init_struc.c \
		srcs/parsing/parsing_utils.c \
		srcs/parsing/init_textures_and_colors.c \
		srcs/parsing/free_struc_elements.c		\
		srcs/parsing/get_elements.c		\
		

OBJS  =	${SRCS:.c=.o}

CC	  =	clang

CFLAGS =	-Wall -Wextra -Werror

LIB   =	-L libft -lft

HEAD  =	-I libft -I includes

RM	  =	rm -f

all: ${NAME}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.c.o:
	${CC} ${CFLAGS} -c ${HEAD} $< -o ${<:.c=.o} -g

${NAME}: ${OBJS}
	make -C libft
	${CC} ${CFLAGS} ${OBJS} ${HEAD} ${LIB} -o ${NAME} -g

.PHONY: all re clean fclean bonus
