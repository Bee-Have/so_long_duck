NAME = so_long

CC = gcc
CGLAGS = -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

SRCS_DIR =  $(shell find Srcs -type d)

OBJS_DIR = Objs
INC_DIR = ./Includes/so_long
LIBFT_DIR = ./Libs/libft_duck
GETFILE_DIR = ./Libs/Lib_get_file

OS = $(shell uname)
ifeq ($(OS), Linux)
MLX_DIR = ./Libs/minilibx-linux
else
MLX_DIR = ./Libs/minilibx-mac
endif

OPENGL = -lm -lbsd -lX11 -lXext
ifeq ($(OS), Linux)
LIBS = -L$(LIBFT_DIR) -lft -L$(GETFILE_DIR) -lgetfile -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
LIBS = -L$(LIBFT_DIR) -lft -L$(GETFILE_DIR) -lgetfile -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
INCLUDES = -I$(LIBFT_DIR)/Includes -I$(GETFILE_DIR)/Includes -I$(MLX_DIR) -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.c \
	debug.c \
	error_message.c End.c \
	map_parsing.c parsing_utils.c \
	mlx_event_manager.c \
	init_struct.c lstnew_anim.c \
	init_mlx.c \
	mlx_printer.c mlx_print_utils.c mlx_event_manager.c \
	textures.c \
	pj_move.c
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: Libs $(NAME)

Libs:
	make -C $(LIBFT_DIR) all
	make -C $(GETFILE_DIR) all
	make -C $(MLX_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

allre: cleanall all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

cleanall: fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(GETFILE_DIR) fclean
	make -C $(MLX_DIR) clean

.PHONY : cleanall fclean clean allre re Libs all
