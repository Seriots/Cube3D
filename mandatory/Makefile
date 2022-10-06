NAME := cub3D
CFLAGS := 
CC := cc
MAKE = /bin/make

define SRCS :=
	srcs/main.c
	srcs/game/event/c3d_default_event.c
	srcs/game/event/c3d_event.c
	srcs/game/init/c3d_init_game.c
	srcs/game/init/c3d_init_images.c
	srcs/game/init/c3d_init_mlx.c
	srcs/game/init/c3d_init_player.c
	srcs/game/init/c3d_init_textures.c
	srcs/game/loop/display/raycasting/c3d_raycasting_display.c
	srcs/game/loop/display/raycasting/c3d_raycasting_getwall.c
	srcs/game/loop/display/raycasting/c3d_raycasting.c
	srcs/game/loop/display/raycasting/c3d_default_display.c
	srcs/game/loop/update/default/c3d_default_update.c
	srcs/game/loop/update/default/c3d_minimap_update.c
	srcs/game/loop/update/default/c3d_player_collide.c
	srcs/game/loop/update/default/c3d_player_update.c
	srcs/game/loop/c3d_loop.c
	srcs/game/c3d_start.c
	srcs/parsing/c3d_parsing_check.c
	srcs/parsing/c3d_parsing_readfile.c
	srcs/parsing/c3d_parsing_set.c
	srcs/parsing/c3d_parsing_square_map.c
	srcs/parsing/c3d_parsing_utils.c
	srcs/parsing/c3d_parsing.c
	srcs/utils/c3d_clean.c
	srcs/utils/c3d_error.c
	srcs/utils/c3d_init_image.c
	srcs/utils/c3d_math.c
	srcs/utils/c3d_math2.c
	
endef
SRCS := $(strip $(SRCS))

define HDRS :=
	ft.h
	dict.h
	ft_printf.h
	list.h
	tree.h
	mlx.h
	mlx_int.h
	c3d_parsing.h
	c3d_settings.h
	c3d_struct.h

endef
HDRS := $(strip $(HDRS))

SRCS_DIR := srcs
OBJS_DIR := objs
LIBS_INCS_DIR := include
HDRS_INCS_DIR := include
INCS	:= -I$(LIBS_INCS_DIR) -I$(HDRS_INCS_DIR)
LIB_DIR  := lib

define LIBS :=
	lib/dict/libdict.a
	lib/ft_printf/libft_printf.a
	lib/ft/libft.a
	lib/list/liblist.a
	lib/tree/libtree.a
	lib/mlx/libmlx_Linux.a
endef
LIBS := $(strip $(LIBS))

define LIB_NAMES :=
	dict
	ft_printf
	ft
	list
	tree
	mlx
endef
LIB_NAMES := $(strip $(LIB_NAMES))

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o, $(SRCS))
DEP_FILES := $(OBJ_FILES:.o=.d)
HDR_FILES := $(addprefix $(INCS_DIR)/,$(HDRS))

CFLAGS := $(CFLAGS) -Wall -Wextra -g3

ifdef DEBUG
	CFLAGS := $(CFLAGS) -g3 -D DEBUG=1
else
	CFLAGS := $(CFLAGS) -Werror -D DEBUG=0
endif

ifdef HIDE
	CFLAGS := $(CFLAGS) -g3 -D HIDE=1
else
	CFLAGS := $(CFLAGS) -Werror -D HIDE=0
endif

# ============================================================================ #
#                                 Functions                                    #
# ============================================================================ #

all: $(NAME)

start_compiling:
	@echo "$(_GREEN)Start Compiling $(_NO_COLOR)"
.INTERMEDIATE:	start_compiling

clean:
	@echo "$(_RED)Objs and Deps: removing$(_NO_COLOR)"
	@rm -vf $(OBJ_FILES) $(DEP_FILES)
	@if [ -d $(OBJS_DIR) ]; then \
		find $(OBJS_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi
.PHONY: clean

fclean: clean
	@echo "\n$(_RED)$(NAME): removing$(_NO_COLOR)"
	rm -f $(NAME)
	@for lib in $(LIB_NAMES); do \
		echo "\n$(_RED)$${lib}: cleaning$(_NO_COLOR)"; \
		$(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ fclean 2> /dev/null \
		|| $(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ clean 2> /dev/null \
		|| echo "Cannot be clean"; \
	done
.PHONY: fclean

re:	fclean
	$(MAKE) all
.PHONY: re

launch:	all
	@./cub3D maps/map1.cub
.PHONY: re


# ============================================================================ #
#                                   Colors                                     #
# ============================================================================ #

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m

# ============================================================================ #
#                                   Rules                                      #
# ============================================================================ #

$(NAME): Makefile $(LIBS) $(OBJ_FILES)
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) -lXext -lX11 -lm

$(OBJS_DIR)/%.o: %.c  start_compiling
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(CC) $(CFLAGS) -MMD $(INCS) -o $@ -c $<

-include $(DEP_FILES)

%.a:
	@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
	@echo ""
