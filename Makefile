# Configuration ------------------------------- #
NAME = main ######################### CHANGE THIS
INC_PATH = sources/includes libraries/mlx
OBJ_PATH = sources/obj
VPATH = sources sources/utils

# Files --------------------------------------- #
LIBS = libraries/mlx/libmlx_Linux.a
SRCS = main.c fdf_init.c fdf_read.c events.c draw.c \
float_limits.c int_limits.c read_utils.c

# Flags --------------------------------------- #
CC = gcc-13
CFLAGS = -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto=auto -fstrict-aliasing -lXext -lX11 -lm -lz
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wduplicated-branches -Wduplicated-cond 
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math

# Pattern Rule -------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking Rule -------------------------------- #
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Phonies ------------------------------------- #
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