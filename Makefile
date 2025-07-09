CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
#F_SANITIZE	=	-fsanitize=address
DEBUG_FLAGS =	-g $(F_SANITIZE)
DEBUG_EXEC	=	debug
NAME		=	so_long
HEADER		=	so_long.h
GNL_FOLDER	=	get_next_line/
GNL_LIB		=	$(GNL_FOLDER)get_next_line.a
PF_FOLDER	=	ft_printf/
PF_LIB		=	$(PF_FOLDER)libftprintf.a
LFT_FOLDER	=	$(PF_FOLDER)libft/
LFT_LIB		=	$(LFT_FOLDER)libft.a
MLX_FOLDER	=	minilibx/
MLX_LIB		=	$(MLX_FOLDER)libmlx.a
#LX11_MAC	=	-L$(MLX_FOLDER) -I$(MLX_LIB) -framework OpenGL -L/usr/X11/lib -framework AppKit
LX11_LINUX	=	-lX11 -lXext -lm
LIBS		=	$(LX11_MAC) $(LX11_LINUX) $(MLX_LIB) $(PF_LIB) $(GNL_LIB)

SRC			=	debug.c so_long.c so_long__camera.c so_long__frames.c \
				so_long__gameplay.c so_long__gameplay_moves.c so_long__init.c \
				so_long__map_checker.c so_long__map_get.c \
				so_long__path_checker.c so_long__quit.c
OBJ			=	$(SRC:.c=.o)

all			:	submodules $(NAME)

submodules	:
	@git submodule update --init --recursive
	@$(MAKE) -C $(GNL_FOLDER)
	@$(MAKE) -C $(LFT_FOLDER)
	@$(MAKE) -C $(PF_FOLDER)
	@$(MAKE) -C $(MLX_FOLDER)

$(NAME)		: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o $(NAME)

%.o			: %.c $(HEADER)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

clean		:
	@rm -f $(OBJ)
	@$(MAKE) -C $(GNL_FOLDER) clean
	@$(MAKE) -C $(PF_FOLDER) clean
	@$(MAKE) -C $(MLX_FOLDER) clean

fclean		: clean
	@rm -f $(NAME) $(DEBUG_EXEC) $(GNL_LIB) $(PF_LIB) $(LFT_LIB) $(MLX_LIB)

re			: fclean all

debug		: fclean submodules $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) -o debug

.PHONY: all clean fclean re submodules debug