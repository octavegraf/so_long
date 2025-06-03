CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
DEBUG		=	-g
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
	$(CC) $(OBJ) $(CFLAGS) $(LIBS) -o $(NAME)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	@rm -f $(OBJ)

fclean		: clean
	@rm -f $(NAME)

re			: fclean all

debug		: fclean $(OBJ)

	$(CC) $(OBJ) $(CFLAGS) $(DEBUG) $(LIBS) -o $(NAME)

.PHONY: all clean fclean re submodules debug