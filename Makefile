NAME = so_long

CC = gcc
CGLAGS = -Wall -Wextra -Werror

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

SRCS_DIR = $(shell find Srcs -type d)

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
LIBS = -L$(LIBFT_DIR) -lft -L$(GETFILE_DIR) -lgetfile -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
LIBS = -L$(LIBFT_DIR) -lft -L$(GETFILE_DIR) -lgetfile -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
INCLUDES = -I$(LIBFT_DIR)/Includes -I$(GETFILE_DIR)/Includes -I$(MLX_DIR) -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.c \
	print_manager.c \
	error_message.c free_manager.c \
	path_parsing.c map_parsing.c \
	init_struct.c init_mlx.c \
	init_anim.c init_sprites.c \
	init_mobs.c init_mobs_utils.c \
	init_gameplay.c \
	pj_move.c mob_move.c exit_update.c \
	mlx_printer.c mlx_print_utils.c mlx_event_manager.c \
	get_sprites.c

SRCS_BONUS = main_bonus.c \
	print_manager.c \
	error_message.c free_manager.c \
	path_parsing.c map_parsing.c \
	init_struct.c init_mlx.c \
	init_anim.c init_sprites.c \
	init_mobs.c init_mobs_utils.c \
	init_gameplay.c \
	pj_move.c mob_move.c exit_update.c \
	mlx_printer.c mlx_print_utils.c mlx_event_manager.c \
	get_sprites.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

OBJS_BONUS = $(addprefix $(OBJS_DIR)/,$(SRCS_BONUS:.c=.o))

all: $(LIBFT_DIR)/libft.a $(GETFILE_DIR)/libgetfile.a $(MLX_DIR)/libmlx.a $(NAME)

bonus: $(LIBFT_DIR)/libft.a $(GETFILE_DIR)/libgetfile.a $(MLX_DIR)/libmlx.a $(NAME)/bonus

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR) all

$(GETFILE_DIR)/libgetfile.a:
	make -C $(GETFILE_DIR) all

$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(NAME)/bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBS)

$(OBJS_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

rebonus: fclean bonus

allre: cleanall all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

cleanall: fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(GETFILE_DIR) fclean
	make -C $(MLX_DIR) clean

.PHONY : cleanall fclean clean allre rebonus re bonus all
