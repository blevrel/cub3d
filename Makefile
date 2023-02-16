NAME  =	cub3D

SRCS  =	srcs/main_processes/cub3d.c \
		srcs/main_processes/launch_game.c	\
		srcs/main_processes/open_window.c	\
		srcs/draw_pixels/my_pixel_put.c	\
		srcs/draw_pixels/draw_vertical_line.c	\
		srcs/display_minimap/display_minimap.c	\
		srcs/display_minimap/get_triangle_coordinates.c	\
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
		srcs/raycasting/raycasting_render.c	\
		

OBJS  =	${SRCS:.c=.o}

CC	  =	clang

CFLAGS =	-Wall -Wextra -Werror

LIB   =	-L mlx_linux -lmlx -lXext -lX11 -L libft -lft -lm

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
