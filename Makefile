# Configuration ------------------------------- #
NAME = main
INC_PATH = sources/includes libraries/libft/sources/includes libraries/mlx
OBJ_PATH = sources/obj
VPATH = sources
# Files --------------------------------------- #
LIBS = libraries/mlx/libmlx_Linux.a libraries/libft/libft.a
SRCS = input_parsing.c
# Flags --------------------------------------- #
CC = gcc-13 -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto=auto -fstrict-aliasing -lXext -lX11 -lm -lz
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wsign-conversion -Wswitch-default -Wduplicated-branches -Wduplicated-cond 
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math
# --------------------------------------------- #
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

debug: $(OBJS)
	@$(MAKE) fclean
	@$(MAKE) all "CC=$(CC) $(DEBUG) $(SANITIZERS)"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug