# Configuration ------------------------------- #
NAME = main
INC_PATH = sources/includes libraries/mlx ../libft/sources/includes
OBJ_PATH = sources/obj
VPATH = sources
# Files --------------------------------------- #
LIBS = libraries/mlx/libmlx_Linux.a ../libft/libft.a
SRCS = fdf_main.c cmlx_functions.c cmlx_events.c fdf_draw.c fdf_read.c fdf_orth.c fdf_init.c
# Flags --------------------------------------- #
CC = gcc-13
CFLAGS = -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto=auto -fstrict-aliasing -lXext -lX11 -lm -lz
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wsign-conversion -Wswitch-default -Wduplicated-branches -Wduplicated-cond 
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math
# --------------------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

# Linking Rule
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Pattern Rule
$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

debug: CFLAGS += $(DEBUG) $(SANITIZERS)
debug: clean $(NAME)

fast: CFLAGS += $(FAST)
fast: clean $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re fast debug