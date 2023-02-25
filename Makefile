# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 16:25:08 by lpaulo-m          #+#    #+#              #
#    Updated: 2023/02/25 19:55:20 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CC_BASIC = $(CC) \
	$(CCF_INCLUDES)

CC_STRICT = $(CC_BASIC) \
	$(CCF_STRICT)

CC_FULL = $(CC_STRICT) \
	$(CCF_DEBUG)
#	$(CCF_LEAK) \
#	$(CCF_OPTIMIZATION) \

CCF_INCLUDES = -I $(LIBFT_INCLUDES) -I $(INCLUDES_PATH)
CCF_STRICT = -Wall -Wextra -Werror
CCF_OPTIMIZATION = -O3
CCF_DEBUG = -g
CCF_LEAK = -fsanitize=leak

CCF_LIBS = -lm -lbsd -lmlx -lXext -lX11

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp
OPEN_IMAGE = ffplay

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
ARCHIVES_PATH = ./archives

LIBS_PATH = ./libs

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INCLUDES = $(LIBFT_PATH)/includes

################################################################################
# MANDATORY
################################################################################

M_HEADER = $(INCLUDES_PATH)/minirt.h
M_ARCHIVE = $(ARCHIVES_PATH)/minirt.a

M_SOURCES_PATH = $(SOURCES_PATH)/mandatory
M_OBJECTS_PATH = $(OBJECTS_PATH)/mandatory

M_SOURCES = ./sources/mandatory/algebra/3d_space.c ./sources/mandatory/algebra/c3d.c ./sources/mandatory/algebra/comparisons.c ./sources/mandatory/algebra/doubles.c ./sources/mandatory/algebra/magnitude.c ./sources/mandatory/algebra/meta_vectors.c ./sources/mandatory/algebra/mx_arithmetic.c ./sources/mandatory/algebra/mx.c ./sources/mandatory/algebra/mx_cofactors.c ./sources/mandatory/algebra/mx_columns.c ./sources/mandatory/algebra/mx_determinants.c ./sources/mandatory/algebra/mx_inverse.c ./sources/mandatory/algebra/mx_multiply.c ./sources/mandatory/algebra/mx_rows.c ./sources/mandatory/algebra/mx_scalar.c ./sources/mandatory/algebra/mx_transformations.c ./sources/mandatory/algebra/mx_tuple.c ./sources/mandatory/algebra/operations.c ./sources/mandatory/algebra/point.c ./sources/mandatory/algebra/quadratic.c ./sources/mandatory/algebra/rays.c ./sources/mandatory/algebra/rays_mx.c ./sources/mandatory/algebra/rgb.c ./sources/mandatory/algebra/scalar.c ./sources/mandatory/algebra/tuple.c ./sources/mandatory/algebra/vector.c ./sources/mandatory/control/ambient_light.c ./sources/mandatory/control/arguments.c ./sources/mandatory/control/camera_1.c ./sources/mandatory/control/camera_2.c ./sources/mandatory/control/debug.c ./sources/mandatory/control/light.c ./sources/mandatory/control/memory.c ./sources/mandatory/control/mlx.c ./sources/mandatory/control/objects.c ./sources/mandatory/control/scene_path.c ./sources/mandatory/control/singleton.c ./sources/mandatory/control/window.c ./sources/mandatory/cylinders/create.c ./sources/mandatory/cylinders/intersect.c ./sources/mandatory/cylinders/normal.c ./sources/mandatory/files/close.c ./sources/mandatory/files/open.c ./sources/mandatory/ft_libbmp/destroy.c ./sources/mandatory/ft_libbmp/die.c ./sources/mandatory/ft_libbmp/draw.c ./sources/mandatory/ft_libbmp/draw_pixel.c ./sources/mandatory/ft_libbmp/free.c ./sources/mandatory/ft_libbmp/get_pixel.c ./sources/mandatory/ft_libbmp/initialize_bm.c ./sources/mandatory/ft_libbmp/initialize_image.c ./sources/mandatory/ft_libbmp/int.c ./sources/mandatory/ft_libbmp/rgb.c ./sources/mandatory/ft_libbmp/rgb_constants.c ./sources/mandatory/ft_libbmp/save_bm.c ./sources/mandatory/ft_libbmp/save.c ./sources/mandatory/ft_libbmp/trgb.c ./sources/mandatory/ft_libbmp/utils.c ./sources/mandatory/mlx/mlx_handler.c ./sources/mandatory/objects/create.c ./sources/mandatory/objects/instersect.c ./sources/mandatory/objects/lighting.c ./sources/mandatory/objects/material.c ./sources/mandatory/objects/normal.c ./sources/mandatory/objects/reflect.c ./sources/mandatory/objects/rotate.c ./sources/mandatory/objects/rotate_fast.c ./sources/mandatory/objects/scale.c ./sources/mandatory/objects/transform.c ./sources/mandatory/objects/translate.c ./sources/mandatory/parser/fields.c ./sources/mandatory/parser/objects.c ./sources/mandatory/parser/parse.c ./sources/mandatory/parser/singletons.c ./sources/mandatory/planes/create.c ./sources/mandatory/planes/intersect.c ./sources/mandatory/planes/normal.c ./sources/mandatory/runtime/cleanup.c ./sources/mandatory/runtime/die.c ./sources/mandatory/runtime/quit.c ./sources/mandatory/scene/light.c ./sources/mandatory/sorters/sort_intersections.c ./sources/mandatory/spheres/create.c ./sources/mandatory/spheres/intersect.c ./sources/mandatory/spheres/normal.c ./sources/mandatory/transformations/rotations.c ./sources/mandatory/transformations/scaling.c ./sources/mandatory/transformations/shearing.c ./sources/mandatory/transformations/translation.c ./sources/mandatory/transformations/view.c ./sources/mandatory/validator/ambient.c ./sources/mandatory/validator/camera.c ./sources/mandatory/validator/color.c ./sources/mandatory/validator/coordinates.c ./sources/mandatory/validator/cylinder.c ./sources/mandatory/validator/light.c ./sources/mandatory/validator/plane.c ./sources/mandatory/validator/scene.c ./sources/mandatory/validator/sphere.c ./sources/mandatory/validator/utils.c ./sources/mandatory/validator/validate.c ./sources/mandatory/world/color.c ./sources/mandatory/world/computations.c ./sources/mandatory/world/default.c ./sources/mandatory/world/hit.c ./sources/mandatory/world/intersect.c ./sources/mandatory/world/ray.c ./sources/mandatory/world/render.c ./sources/mandatory/world/shade.c ./sources/mandatory/world/shadows.c

M_OBJECTS = $(patsubst $(M_SOURCES_PATH)/%.c, $(M_OBJECTS_PATH)/%.o, $(M_SOURCES))
M_OBJECT_DIRECTORIES = $(sort $(dir $(M_OBJECTS)))

M_MAIN = ./main.c

M_ARCHIVES = $(M_ARCHIVE) $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT) $(M_ARCHIVE)
	$(CC_FULL) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

$(M_ARCHIVE): $(M_HEADER) $(M_OBJECTS)
	$(ARCHIVE_AND_INDEX) $(M_ARCHIVE) $(M_OBJECTS)

$(M_OBJECTS_PATH)/%.o: $(M_SOURCES_PATH)/%.c
	$(CC_FULL) -c -o $@ $<

clean:
	$(REMOVE) $(M_OBJECTS)
	$(REMOVE) $(M_ARCHIVE)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

################################################################################
# DIRS
################################################################################

dirs: $(ARCHIVES_PATH) $(OBJECTS_PATH) \
	$(M_OBJECT_DIRECTORIES) $(B_OBJECT_DIRECTORIES)

$(ARCHIVES_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(OBJECTS_PATH):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

$(M_OBJECT_DIRECTORIES):
	$(SAFE_MAKEDIR) $@ && touch "$@.keep"

################################################################################
# CLEAN
################################################################################

tclean: clean_libs fclean fcleanb tests_clean example_clean vglog_clean

################################################################################
# LIBS
################################################################################

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH) all

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean_libs: libft_clean

################################################################################
# RUN
################################################################################

run: re
	./$(NAME) scenes/subject.rt
#	./$(NAME) scenes/inside.rt
#	./$(NAME) scenes/walls.rt
#	./$(NAME) scenes/plane_2.rt
#	./$(NAME) scenes/cylinder_2.rt
#	./$(NAME) scenes/rgb_balls.rt
#	./$(NAME) scenes/blue_light.rt
#	./$(NAME) scenes/bad_cam_look_at.rt
#	$(OPEN_IMAGE) bitmaps/camera_1.bmp

################################################################################
# TESTS
################################################################################

CC_TEST = $(CC_BASIC) \
	$(CCF_DEBUG) \
	$(CCF_LEAK)

CC_VGTEST = $(CC_BASIC) \
	$(CCF_DEBUG)

TESTS_PATH = ./tests

TEST_SOURCES = $(wildcard $(TESTS_PATH)/**/*.c) $(wildcard $(TESTS_PATH)/*.c)

TESTS = $(patsubst $(TESTS_PATH)/%.c, $(TESTS_PATH)/%.out, $(TEST_SOURCES))
VGTESTS = $(patsubst $(TESTS_PATH)/%.c, $(TESTS_PATH)/%.vg.out, $(TEST_SOURCES))

tests: test_re $(TESTS)

test: test_re $(TESTS_PATH)/$t.out

$(TESTS_PATH)/%.out: $(TESTS_PATH)/%.c
	$(CC_TEST)\
		$< \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $@
	./$@

vgtests: test_re $(VGTESTS)

vgtest: test_re $(TESTS_PATH)/$t.vg.out

$(TESTS_PATH)/%.vg.out: $(TESTS_PATH)/%.c
	$(CC_VGTEST)\
		$< \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $@
	$(VG) $(VG_FLAGS) ./$@

test_re: re tests_clean

tests_clean:
	$(REMOVE_RECURSIVE) $(TESTS) $(VGTESTS)

################################################################################
# EXAMPLE
################################################################################

EXAMPLES_PATH = ./examples

EXAMPLE_MAIN = $(EXAMPLES_PATH)/example.c
EXECUTE_EXAMPLE = ./a.out
EXAMPLE_GARBAGE = a.out a.out.dSYM

example: build_example
	$(EXECUTE_EXAMPLE)

build_example: $(M_ARCHIVE)
	$(CC_FULL) \
		$(EXAMPLE_MAIN) \
		$(M_ARCHIVES)

example_clean: fclean
	$(REMOVE_RECURSIVE) $(EXAMPLE_GARBAGE)

################################################################################
# VALGRIND
################################################################################

CC_VG = $(CC) \
	$(CCF_INCLUDES) \
	$(CCF_STRICT)

VG = valgrind

VG_FLAGS = --leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \

VG_LOG_FLAGS = $(VG_FLAGS) \
	--log-file=$(VG_LOG) \
	--track-origins=yes \
	--verbose
VG_LOG = valgrind_leaks.log

VG_TARGET = ./miniRT
VG_SCENE_PATH = scenes/plane_1.rt

vg: vg_build
	$(VG) $(VG_FLAGS) $(VG_TARGET) $(VG_SCENE_PATH)

vglog: vg_build
	$(VG) $(VG_LOG_FLAGS) $(VG_TARGET) $(VG_SCENE_PATH)

vg_build: clean $(NAME)
	$(CC_VG) \
		$(M_MAIN) \
		$(M_ARCHIVES) \
		$(CCF_LIBS) \
		-o $(NAME)

vglog_clean: fclean
	$(REMOVE) $(VG_LOG)

################################################################################
# MISC
################################################################################

norm:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) norm

	@printf "\n$(G)=== No norminette errors found in $(LIBFT_PATH) ===$(RC)\n\n"
	norminette $(INCLUDES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(INCLUDES_PATH) ===$(RC)\n\n"
	norminette $(SOURCES_PATH)
	@printf "\n$(G)=== No norminette errors found in $(SOURCES_PATH) ===$(RC)\n\n"
	norminette $(M_MAIN)
	@printf "\n$(G)=== No norminette errors found in $(M_MAIN) ===$(RC)\n\n"

git:
	git add -A
	git commit -m "AUTOMATIC MESSAGE"
	git push

gitm:
	git add -A
	git commit -m $m
	git push

dump_sources:
	@echo =========== MANDATORY ===========
	@echo "M_SOURCES = $(M_SOURCES)"
	@echo ============= BONUS =============
	@echo "B_SOURCES = $(B_SOURCES)"
	@echo =================================

################################################################################
# PHONY
################################################################################

.PHONY: \
all clean fclean re \
\
dirs \
\
tclean \
\
libft_clean clean_libs \
\
run \
\
tests test vgtests vgtest test_re tests_clean \
\
example build_example example_clean \
\
vg vglog vg_build vglog_clean \
\
norm git gitm dump_sources

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
