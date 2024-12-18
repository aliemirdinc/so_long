NAME			= so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= lib/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lXext -lX11
MLX				= ./lib/minilibx-linux/libmlx.a

REMOVE 			= rm -f

SRCS_DIR		= ./src/

SRCS 			= $(addprefix $(SRCS_DIR),\
				ft_check_command_line_args.c \
				ft_msg.c ft_init_game.c\
				ft_check_map.c ft_init_map.c\
				so_long.c ft_mem_free.c ft_render_frame.c\
				ft_flood_fill.c ft_handle_buttons.c)

all:			${MLX} ${LIBFT} ${NAME} 

${NAME}:
	${CC} ${STANDARD_FLAGS} ${SRCS} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -g3 -o ${NAME}
	@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
	@echo

${MLX}:
	@echo "Compiling MLX..."
	make -C lib/minilibx-linux
	make clean lib/minilibx-linux
	@echo "MLX compiled successfully."

${LIBFT}:
	@echo "Compiling libft..."
	make -C lib/libft
	make clean lib/libft
	@echo "libft compiled successfully."

clean:
	make clean -C lib/libft
	@echo

fclean:
	${REMOVE} ${NAME}
	@echo "${NAME}: ${RED}${NAME} was deleted${RESET}"
	@echo

re:	fclean all

run: re
	./${NAME} assets/maps/valid/map2.ber 

.PHONY:	all clean fclean re run
