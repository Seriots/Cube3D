NAME := cub3D
CFLAGS := 
CC := cc
MAKE = /bin/make

define SRCS :=
		main.c
		game/event/c3d_default_event.c
		game/event/c3d_event.c
		game/init/c3d_init_game.c
		game/init/c3d_init_images.c
		game/init/c3d_init_mlx.c
		game/init/c3d_init_player.c
		game/init/c3d_init_textures.c
		game/loop/display/raycasting/c3d_raycasting_display.c
		game/loop/display/raycasting/c3d_raycasting_getwall.c
		game/loop/display/raycasting/c3d_raycasting.c
		game/loop/display/raycasting/c3d_default_display.c
		game/loop/update/default/c3d_default_update.c
		game/loop/update/default/c3d_minimap_update.c
		game/loop/update/default/c3d_player_collide.c
		game/loop/update/default/c3d_player_update.c
		game/loop/c3d_loop.c
		game/c3d_start.c
		parsing/c3d_parsing_check.c
		parsing/c3d_parsing_readfile.c
		parsing/c3d_parsing_set.c
		parsing/c3d_parsing_square_map.c
		parsing/c3d_parsing_utils.c
		parsing/c3d_parsing.c
		utils/c3d_clean.c
		utils/c3d_error.c
		utils/c3d_init_image.c
		utils/c3d_math.c
		utils/c3d_math2.c
	
endef
SRCS := $(strip $(SRCS))

SRCS_DIR := srcs
OBJS_DIR := objs
LIBS_INCS_DIR := include/libs
HDRS_INCS_DIR := include/c3d_headers
INCS := -I $(HDRS_INCS_DIR) -I $(LIBS_INCS_DIR)
LIB_DIR  := ../lib

define LIBS :=
	$(LIB_DIR)/dict/libdict.a
	$(LIB_DIR)/ft/libft.a
	$(LIB_DIR)/mlx/libmlx_Linux.a
endef
LIBS := $(strip $(LIBS))

define LIB_NAMES :=
	dict
	ft
	mlx
endef
LIB_NAMES := $(strip $(LIB_NAMES))

# ============================================================================ #
#                               Intermediates                                  #
# ============================================================================ #

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o, $(SRCS))
DEP_FILES := $(OBJ_FILES:.o=.d)

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

.PHONY: bonus

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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  start_compiling
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(CC) $(CFLAGS) -MMD $(INCS) -o $@ -c $<

-include $(DEP_FILES)
-include $(DEP_FILES_BONUS)

%.a:
	@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
	@echo ""
