# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 13:32:00 by rhvidste          #+#    #+#              #
#    Updated: 2025/10/15 13:49:53 by rhvidste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	Materia
CC			:=	c++
FLAGS		:=	-Wall -Werror -Wextra -std=c++17
DEBUG_FLAGS	:=	-g
# ---------------------------------------------------------------------------- #
INC_DIR		:=	./inc
HEADERS		:=	$(INC_DIR)/AMateria.hpp			\
				$(INC_DIR)/ICharacter.hpp		\
				$(INC_DIR)/IMateriaSource.hpp	\
				$(INC_DIR)/MateriaSource.hpp	\
				$(INC_DIR)/Character.hpp		\
				$(INC_DIR)/Ice.hpp				\
				$(INC_DIR)/Cure.hpp				\
# ---------------------------------------------------------------------------- #
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
# ---------------------------------------------------------------------------- #
SRC			:=	$(SRC_DIR)/main.cpp				\
				$(SRC_DIR)/AMateria.cpp			\
				$(SRC_DIR)/MateriaSource.cpp	\
				$(SRC_DIR)/Character.cpp		\
				$(SRC_DIR)/Ice.cpp				\
				$(SRC_DIR)/Cure.cpp				\

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
