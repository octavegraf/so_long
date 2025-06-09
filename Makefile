CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAGS =	-g
DEBUG_EXEC	=	debug
NAME		=	so_long
HEADER		=	so_long.h
GNL_FOLDER	=	get_next_line/
GNL_LIB		=	$(GNL_FOLDER)get_next_line.a
PF_FOLDER	=	ft_printf/
PF_LIB		=	$(PF_FOLDER)libftprintf.a
MLX_FOLDER	=	minilibx/
MLX_LIB		=	$(MLX_FOLDER)libmlx.a
LIBS		=	-lX11 -lXext -lm $(MLX_LIB) $(PF_LIB)

SRC			=	$(wildcard *.c)
OBJ			=	$(SRC:.c=.o)

all			:	submodules $(NAME)

submodules	:
	@git submodule update --init --recursive
	@$(MAKE) -C $(MLX_FOLDER)
	@$(MAKE) -C $(PF_FOLDER)

$(NAME)		: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o $(NAME)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

clean		:
	@rm -f $(OBJ)

fclean		: clean
	@rm -f $(NAME) $(DEBUG_EXEC) $(MLX_LIB)

re			: fclean all

debug		: fclean submodules $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o debug

.PHONY: all clean fclean re submodules debug