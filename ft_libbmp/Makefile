# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2022/12/01 20:44:41 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_libbmp.a

# CC = cc
# CC = gcc
# CC = clang
CC = clang-12

CC_FLAGS = -Wall -Wextra -Werror
CC_STRICT = $(CC) $(CC_FLAGS)
CC_DEBUG_FLAGS = -g -fsanitize=address

SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
EXAMPLES_PATH = ./examples

HEADER_FILE = ft_libbmp.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCES = $(wildcard $(SOURCES_PATH)/**/*.c) $(wildcard $(SOURCES_PATH)/*.c)
# SOURCES = ./sources/bitmap/draw.c ./sources/bitmap/free.c ./sources/bitmap/initialize.c ./sources/bitmap/save.c ./sources/colors/int.c ./sources/colors/rgb.c ./sources/colors/trgb.c ./sources/errors/die.c ./sources/mlx_image/destroy.c ./sources/mlx_image/initialize.c ./sources/mlx_image/pixels.c ./sources/mlx_image/save_bm.c ./sources/utils.c

OBJECTS = $(subst $(SOURCES_PATH)/,$(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES)))
OBJECT_DIRECTORIES = $(sort $(dir $(OBJECTS)))

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME): $(HEADER) $(OBJECTS)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c
	$(CC_STRICT) -I $(INCLUDES_PATH) -c -o $@ $<

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

################################################################################
# INITIALIZE
################################################################################

initialize: make_dirs

make_dirs: $(OBJECTS_PATH) $(OBJECT_DIRECTORIES)

$(OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

$(BITMAPS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@/.keep"

################################################################################
# EXAMPLE
################################################################################

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
IMAGE_NAME = hello.bmp
EXECUTE_EXAMPLE = ./a.out $(IMAGE_NAME)
OPEN_IMAGE = ffplay
EXAMPLE_GARBAGE = a.out a.out.dSYM $(IMAGE_NAME)

example: re
	$(REMOVE) $(IMAGE_NAME)
	$(CC) $(CC_DEBUG_FLAGS) -I $(INCLUDES_PATH) $(EXAMPLE_MAIN) $(NAME)
	$(EXECUTE_EXAMPLE)
	$(OPEN_IMAGE) $(IMAGE_NAME)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# MISC
################################################################################

norm:
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "update"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== SOURCES ===========
	@echo "SOURCES = $(SOURCES)"
	@echo ===============================

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean initialize \
\
	example example_clean \
\
	norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
Bk = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BkB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC	= \033[0m
