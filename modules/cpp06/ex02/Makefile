# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 14:45:07 by rhvidste          #+#    #+#              #
#    Updated: 2025/10/20 14:45:31 by rhvidste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Serializer
CC			:=	c++
FLAGS		:=	-Wall -Werror -Wextra -std=c++20
DEBUG_FLAGS	:=	-g
# ---------------------------------------------------------------------------- #
INC_DIR		:=	./inc
HEADERS		:=	$(INC_DIR)/Serializer.hpp				\
				$(INC_DIR)/Data.hpp						\
				$(INC_DIR)/ansi_colors.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
# ---------------------------------------------------------------------------- #
SRC			:=	$(SRC_DIR)/main.cpp						\
				$(SRC_DIR)/Serializer.cpp				\
				$(SRC_DIR)/Data.cpp

# ---------------------------------------------------------------------------- #
OBJ			:=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

.SECONDARY: $(OBJ)
# ---------------------------------------------------------------------------- #
RED			:= \033[0;31m
GREEN		:= \033[0;32m
EC			:= \033[0m
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -I $(INC_DIR) $(OBJ) -o $@
	@echo "$(GREEN)$(NAME) created$(EC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# ---------------------------------------------------------------------------- #
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)obj files removed$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Full clean up completed$(EC)"

re: fclean all
# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re
# ---------------------------------------------------------------------------- #
