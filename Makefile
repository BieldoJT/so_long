NAME = so_long

NAME_BONUS = so_long_bonus

MANDATORY_DIR = ./mandatory/

BONUS_DIR = ./bonus/

LIBFT = ./libraries/Libft/libft.a

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

VALGRIND = @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

MANDATORY_SCRS =  $(addprefix $(MANDATORY_DIR),\
				read_map.c \
				print_error.c \
				so_long_utils.c \
				verify_map.c \
				verify_path.c \
				start_game.c \
				render_map.c \
				play_game.c \
				close_game.c \
				main.c)

BONUS_SRCS = $(addprefix $(BONUS_DIR),\
				read_map_bonus.c \
				print_error_bonus.c \
				so_long_utils_bonus.c \
				verify_map_bonus.c \
				verify_path_bonus.c \
				start_game_bonus.c \
				render_map_bonus.c \
				play_game_bonus.c \
				close_game_bonus.c \
				enemy_bonus.c \
				main_bonus.c)


all: ${LIBFT} ${NAME}


${NAME}:
		${CC} ${MANDATORY_SCRS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -g -o ${NAME}
		@echo "\n${NAME} is compiled."
		@echo

bonus: ${LIBFT} ${NAME_BONUS}

${NAME_BONUS}:
		${CC} ${BONUS_SRCS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -g -o ${NAME_BONUS}
		@echo "\n${NAME} is compiled."
		@echo

${LIBFT}:
		make bonus -C libraries/Libft

clean:
		make clean -C libraries/Libft

fclean: clean
		rm -rf ${NAME}
		rm -rf ${NAME_BONUS}

re: fclean all

rebonus: fclean ${NAME_BONUS}


.PHONY:			all clean fclean re rebonus
