NAME = so_long

LIBFT = ./libraries/Libft/libft.a

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

SRCS = read_map.c print_error.c so_long_utils.c verify_map.c verify_path.c start_game.c render_map.c main.c


all: ${LIBFT} ${NAME}


${NAME}:
		${CC} ${SRCS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -g -o ${NAME}
		@echo "\n${NAME} is compiled."
		@echo

${LIBFT}:
		make bonus -C libraries/Libft

ll:
	make bonus -C libraries/Libft

clean:
		make clean -C libraries/Libft

fclean:
		rm -rf ${NAME}

re: fclean all

run: ${NAME}
		#colocar a pasta do mapa aqui
		${VALGRIND} ./${NAME} maps/map.ber

test: ${LIBFT}
		${CC} ${SRCS} ${LIBFT} ${CC_FLAGS} -g -o test
		@echo "\ntest is compiled."
		@echo

clear_test:
		rm -rf ./test

re_test: clear_test test
