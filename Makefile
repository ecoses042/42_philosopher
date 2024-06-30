# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the output executable
NAME = philo

# Source files
SRC = main.c\
	action/action.c\
	init_data/init_input.c\
	init_data/init_mutex.c\
	input_error/check_char.c\
	print/print_error.c\
	print/print_status.c\
	thread/case_1.c\
	thread/init_thread.c\
	utility/atoi.c\
	utility/exit.c\
	utility/find_left_fork.c\
	utility/get_time.c\
	debug.c
	

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the object files into the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I.

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJ)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
