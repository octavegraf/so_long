CC			=	cc
C_FLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAGS =	-g
DEBUG_EXEC	=	debug
NAME		=	so_long
HEADER		=	so_long.h
MLX_FOLDER	=	mlx/
MLX_LIB		=	$(MLX_FOLDER)libmlx.a
LIBS		=	-lX11 -lXext -lm $(MLX_LIB)

SRC			=	$(wildcard *.c)
OBJ			=	$(SRC:.c=.o)

all			:	submodules $(NAME)

submodules	:
	@git submodule update --init --recursive
	@$(MAKE) -C $(MLX_FOLDER)

$(NAME)		: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o $(NAME)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	@rm -f $(OBJ)

fclean		: clean
	@rm -f $(NAME) $(DEBUG_EXEC)

re			: fclean all

debug		: submodules fclean $(OBJ)
	@rm -rf $(DEBUG_EXEC)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o debug

.PHONY: all clean fclean re submodules debug