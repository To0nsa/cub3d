# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 18:23:28 by nlouis            #+#    #+#              #
#    Updated: 2025/04/13 22:56:10 by nlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                          CUB3D MAKEFILE 🧱                                   #
# **************************************************************************** #

# Detect OS for picking correct MiniLibX submodule
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
  MLX_DIR     := mlx_macos
  MLX_FLAGS   := -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
  MLX_DIR     := mlx_linux
  MLX_FLAGS   := -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

# Compiler and flags
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -I include -I libft/include -I $(MLX_DIR)

# Directories
OBJDIR   := objs
LIBDIR   := libft/lib

# Executable
NAME     := cub3D

# Source files
SRC      := $(shell find srcs -name "*.c")

# Object files (mirror the directory structure under objs/)
OBJ      := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Libraries
LIBFT    := $(LIBDIR)/libft.a
MLX_LIB  := $(MLX_DIR)/libmlx.a

# Linker flags
LDFLAGS  := -L libft/lib -lft $(MLX_FLAGS)

# Colors
GREEN    := \033[0;32m
CYAN     := \033[0;36m
YELLOW   := \033[1;33m
RESET    := \033[0m

# Default rule
.DEFAULT_GOAL := all

# **************************************************************************** #
#                              BUILD TARGETS                                   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

# Compile each .c file into an .o file under objs/
$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

# Build libft
$(LIBFT):
	@make -C libft

# Build MLX (platform-specific)
$(MLX_LIB):
	@make -C $(MLX_DIR)

# **************************************************************************** #
#                              CLEAN TARGETS                                   #
# **************************************************************************** #

clean:
	@rm -rf $(OBJDIR)
	@make -C libft clean
	@make -C $(MLX_DIR) clean
	@echo "$(YELLOW)🧹 Cleaned object files for project, libft, and $(MLX_DIR).$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "$(YELLOW)🗑️  Removed binary $(NAME) and libft library.$(RESET)"

re: fclean all

# **************************************************************************** #
#                              SETUP TARGET                                    #
# **************************************************************************** #

setup:
	@echo "$(CYAN)🔧 Attempting to install necessary dependencies...$(RESET)"
	@if [ "$(UNAME)" = "Linux" ]; then \
		echo "Detected Linux. Using apt-get (Debian/Ubuntu style)."; \
		echo "You may be prompted for your sudo password."; \
		sudo apt-get update && sudo apt-get install -y \
			build-essential \
			libx11-dev \
			libxext-dev \
			zlib1g-dev \
			make \
			gcc; \
	elif [ "$(UNAME)" = "Darwin" ]; then \
		echo "Detected macOS. Using Homebrew."; \
		echo "You may be prompted for your sudo password."; \
		brew update && brew install \
			gcc \
			make \
			xquartz; \
	else \
		echo "Unsupported OS. Please install dependencies manually."; \
	fi
	@echo "$(GREEN)✔ Dependencies installation step completed (if no errors).$(RESET)"

.PHONY: all clean fclean re setup

# **************************************************************************** #
#                              💡 USAGE GUIDE                                  #
# **************************************************************************** #
# make            → Build cub3D, libft, and the correct MLX (macOS or Linux)
# make clean      → Remove all object files (in project, libft, and MLX) 🧹
# make fclean     → Remove object files + the cub3D binary + libft.a 🗑️
# make re         → Clean and rebuild everything 🔁
# make setup      → Attempt to install system dependencies for Linux or macOS 🔧
# **************************************************************************** #
