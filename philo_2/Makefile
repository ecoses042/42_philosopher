# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Name of the output executable
NAME = philo

# Source files
SRC = main.c\
	manage_input/check_input.c\
	utility/ft_strlen.c\
	utility/print_error.c\
	utility/ft_atoi.c\
	manage_input/init_data.c\
	utility/get_time.c\
	manage_input/init_philo.c\
	manage_input/manage_thread.c\
	utility/check_status.c\
	debug.c\

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
