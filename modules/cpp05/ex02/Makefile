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

NAME		:=	Shrubbery
CC			:=	c++
FLAGS		:=	-Wall -Werror -Wextra -std=c++20
DEBUG_FLAGS	:=	-g
# ---------------------------------------------------------------------------- #
INC_DIR		:=	./inc
HEADERS		:=	$(INC_DIR)/Bureaucrat.hpp				\
				$(INC_DIR)/AForm.hpp					\
				$(INC_DIR)/ShrubberyCreationForm.hpp	\
				$(INC_DIR)/RobotomyRequestForm.hpp		\
				$(INC_DIR)/PresidentialPardonForm.hpp	\
				$(INC_DIR)/ansi_colors.hpp
# ---------------------------------------------------------------------------- #
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
# ---------------------------------------------------------------------------- #
SRC			:=	$(SRC_DIR)/main.cpp						\
				$(SRC_DIR)/Bureaucrat.cpp				\
				$(SRC_DIR)/AForm.cpp					\
				$(SRC_DIR)/ShrubberyCreationForm.cpp	\
				$(SRC_DIR)/RobotomyRequestForm.cpp		\
				$(SRC_DIR)/PresidentialPardonForm.cpp	

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
	$(CXX) $(FLAGS) -I $(INC_DIR) -c $< -o $@

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
