# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the output executable
NAME = philo

# Source files
SRC = main.c\
	utility/atoi.c\
	input_error/check_char.c\
	init_data/init_philo.c\
	extreme_case/case_1.c\

	

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
