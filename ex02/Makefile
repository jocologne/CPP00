# Makefile for GlobalBanksters United with obj directory

# Compiler settings
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98
NAME        := globalbanksters

# File paths
SRC_DIR     := .
OBJ_DIR     := obj
SRCS        := Account.cpp tests.cpp
OBJS        := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
HEADER      := Account.hpp

# Create obj directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Main rule
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Rule for each object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rules
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re