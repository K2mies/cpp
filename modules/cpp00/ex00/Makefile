#	PROGRAM NAME
NAME = megaphone

#	COMPILATION
CC = c++
CFLAGS = -Wall -Werror -Wextra

# SRC/OBJ FILES
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

# DEFAULT TARGET
all: $(NAME)

# LINKING THE EXECUTABLE
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "-- COMPILED $(NAME)"

# COMPILE OBJECT FILES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

# TESTING
test: $(NAME)
	@echo "Example 1: \"\""
	@./$(NAME)
	@echo "\nExample 2: \"shhhhh... I think the students are asleep...\""
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@echo "\nExample 3: Damnit \" ! \" \"Sorry students, I thought this thing was off.\""
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

# CLEANING OBJECT FILES
clean:
	$(RM) $(OBJ)
	@echo "--CLEANED"

# CLEANING ALL
fclean: clean
	$(RM) $(NAME)
	@echo "--FCLEANED"

# REBUILD
re: fclean all
	@echo "--REBUILD"

# PHONY TARGERTS
.PHONY: all clean fclean re test

