NAME    := fixed
CC      := c++
FLAGS   := -Wall -Werror -Wextra -std=c++17

SRCS    := main.cpp		\
		   Fixed.cpp	\
		   Point.cpp	\
		   bsp.cpp		\

OBJ_DIR := objs/
OBJS    := $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

RED     := \033[0;31m
GREEN   := \033[0;32m
EC      := \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(EC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)obj files removed$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Full clean up completed$(EC)"

re: fclean all

.PHONY: all clean fclean re
