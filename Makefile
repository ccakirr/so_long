# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccakir <ccakir@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 02:00:00 by ccakir            #+#    #+#              #
#    Updated: 2025/11/12 22:50:10 by ccakir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #

RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
RESET   = \033[0m

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iinc -Iget_next_line -Iminilibx-linux -Ift_printf

# Directories
SRC_DIR     = src
UTILS_DIR   = utils
GNL_DIR     = get_next_line
FT_PRINTF_DIR = ft_printf
OBJ_DIR     = obj

# MLX Library
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# FT_PRINTF Library
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/ft_printf.a

# Source Files
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/map.c \
              $(SRC_DIR)/validate.c \
              $(SRC_DIR)/floodfill.c \
              $(SRC_DIR)/load_textures.c \
              $(SRC_DIR)/render.c \
              $(SRC_DIR)/exit_game.c \
              $(SRC_DIR)/game_init.c \
              $(SRC_DIR)/handle_input.c \
              $(UTILS_DIR)/so_long_utils.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

# Object Files
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(MLX_LIB):
	@echo "$(YELLOW)Compiling MLX library...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ MLX library ready!$(RESET)"

$(FT_PRINTF_LIB):
	@echo "$(YELLOW)Compiling ft_printf library...$(RESET)"
	@make -C $(FT_PRINTF_DIR) > /dev/null 2>&1
	@echo "$(GREEN)✓ ft_printf library ready!$(RESET)"

$(NAME): $(MLX_LIB) $(FT_PRINTF_LIB) $(OBJS)
	@if [ ! -f $(NAME) ]; then \
		echo "$(YELLOW)Linking $(NAME)...$(RESET)"; \
		$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME); \
		echo "$(GREEN)✓ $(NAME) created!$(RESET)"; \
	else \
		if [ $(shell find $(OBJS) -newer $(NAME) 2>/dev/null | wc -l) -gt 0 ]; then \
			echo "$(YELLOW)Relinking $(NAME)...$(RESET)"; \
			$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(MLX_FLAGS) -o $(NAME); \
			echo "$(GREEN)✓ $(NAME) updated!$(RESET)"; \
		else \
			echo "$(GREEN)✓ $(NAME) is up to date!$(RESET)"; \
		fi \
	fi

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) clean > /dev/null 2>&1
	@echo "$(GREEN)✓ Clean complete!$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(MLX_DIR) clean > /dev/null 2>&1
	@make -C $(FT_PRINTF_DIR) fclean > /dev/null 2>&1
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

re: fclean all

run: all
	@./$(NAME) maps/test.ber

.PHONY: all clean fclean re run