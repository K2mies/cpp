NAME = BankAccount
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
