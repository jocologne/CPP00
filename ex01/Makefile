# Compiler and flags
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
INCLUDES := -I.

# Project name and files (using lowercase)
NAME     := phonebook
SRC_DIR  := .
OBJ_DIR  := obj
SRCS     := main.cpp Phonebook.cpp Contact.cpp
OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Colors for output
GREEN    := \033[0;32m
RED      := \033[0;31m
NC       := \033[0m

# Main rule
all: $(NAME)

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "$(GREEN)Compiling$(NC) $<"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Linking rule
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking$(NC) $(NAME)"
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(GREEN)Build successful!$(NC) Run with: ./$(NAME)"

# Clean rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed$(NC) object files"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed$(NC) executable $(NAME)"

re: fclean all

.PHONY: all clean fclean re