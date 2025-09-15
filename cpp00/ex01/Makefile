NAME = phonebook

# compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20

SRC =
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

# Build main executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "build successfull: $(NAME)"

# Compile object files
%.o: %.cpp
	@echo "compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJ)
	@echo "Objects cleaned"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "All executables removed"

# Rebuild everything
re: fclean all

.PHONY:	all clean fclean re
