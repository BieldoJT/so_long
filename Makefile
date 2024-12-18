NAME = so_long

LIBFT = ./libraries/Libft/libft.a

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

SRCS = read_map.c print_error.c so_long_utils.c verify_map.c verify_path.c start_game.c render_map.c play_game.c close_game.c main.c


all: ${LIBFT} ${NAME}


${NAME}:
		${CC} ${SRCS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -g -o ${NAME}
		@echo "\n${NAME} is compiled."
		@echo

${LIBFT}:
		make bonus -C libraries/Libft

clean:
		make clean -C libraries/Libft

fclean: clean
		rm -rf ${NAME}

re: fclean all

