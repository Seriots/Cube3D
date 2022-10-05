NAME := cub3D
CFLAGS := 
CC := cc
MAKE = /bin/make

define SRCS :=
	main.c
	game/event/c3d_default_event_mouse.c
	game/event/c3d_default_event.c
	game/event/c3d_event_mouse.c
	game/event/c3d_event.c
	game/c3d_start.c
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
	map_generator/mzg_clean.c
	map_generator/mzg_fillmap_check.c
	map_generator/mzg_fillmap.c
	map_generator/mzg_generator.c
	map_generator/mzg_get_maze.c
	map_generator/mzg_makemaze.c
	map_generator/mzg_makeshape.c
	map_generator/mzg_post_player.c
	map_generator/mzg_printmaze.c
	map_generator/mzg_standardize.c
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
	utils/c3d_time.c
	
endef
SRCS := $(strip $(SRCS))

define SRCS_BONUS :=
	game/loop/display/menu/c3d_display_button.c
	game/loop/display/menu/c3d_display_checkbox.c
	game/loop/display/menu/c3d_display_keyinput.c
	game/loop/display/menu/c3d_display_slidebar.c
	game/loop/display/menu/c3d_display_textinput.c
	game/loop/display/menu/c3d_display_numinput.c
	game/loop/display/menu/c3d_menu_display.c
	game/loop/update/menu/c3d_menu_update.c
	game/loop/update/menu/c3d_draw_button.c
	game/loop/update/menu/c3d_draw_checkbox.c
	game/loop/update/menu/c3d_draw_keyinput.c
	game/loop/update/menu/c3d_draw_textinput.c
	game/loop/update/menu/c3d_draw_numinput.c
	game/loop/update/menu/c3d_draw_slidebar.c
	game/loop/update/menu/c3d_draw_scrollbar.c
	game/event/c3d_menu_event.c
	game/event/c3d_menu_event_mouse.c
	game/event/c3d_openclose_menu.c
	game/init/c3d_init_menu.c
	menu/c3d_button_exit.c
	menu/c3d_button_resume.c
	menu/c3d_checkbox_color.c
	menu/c3d_checkbox_invertscroll.c
	menu/c3d_keyinput_forward.c
	menu/c3d_keyinput_backward.c
	menu/c3d_keyinput_left.c
	menu/c3d_keyinput_right.c
	menu/c3d_numinput_ceil.c
	menu/c3d_numinput_floor.c
	menu/c3d_scrollbar.c
	menu/c3d_slidebar_camspeedx.c
	menu/c3d_slidebar_camspeedy.c
	menu/c3d_slidebar_fov.c
	menu/c3d_slidebar_scrollspeed.c
	menu/c3d_textinput_east.c
	menu/c3d_textinput_north.c
	menu/c3d_textinput_south.c
	menu/c3d_textinput_west.c
	utils/c3d_menu_utils.c
	utils/c3d_menu_utils2.c
	utils/c3d_menu_utils3.c
	utils/c3d_menu_utils4.c
	
endef
SRCS_BONUS := $(strip $(SRCS_BONUS))

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
INCS_DIR := include
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

OBJ_FILES := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))
OBJ_FILES_BONUS := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS_BONUS))
DEP_FILES := $(OBJ_FILES:.o=.d)
DEP_FILES_BONUS := $(OBJ_FILES_BONUS:.o=.d)
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
	@rm -vf $(OBJ_FILES) $(OBJ_FILES_BONUS) $(DEP_FILES) $(DEP_FILES_BONUS)
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

$(NAME): Makefile $(LIBS) $(OBJ_FILES) $(OBJ_FILES_BONUS)
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(OBJ_FILES_BONUS) $(LIBS) -lXext -lX11 -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  start_compiling
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
		echo "\n$(_BLUE)$(dir $@): Create$(_NO_COLOR)"; \
	fi
	$(CC) $(CFLAGS) -MMD -I $(INCS_DIR) -o $@ -c $<

-include $(DEP_FILES)
-include $(DEP_FILES_BONUS)

%.a:
	@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
	@echo ""
