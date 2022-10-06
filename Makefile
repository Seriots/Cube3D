NAME := cub3D
CFLAGS := 
CC := cc
MAKE = /bin/make

define SRCS :=
	srcs_mandatory/main.c
	srcs_mandatory/game/event/c3d_default_event.c
	srcs_mandatory/game/event/c3d_event.c
	srcs_mandatory/game/init/c3d_init_game.c
	srcs_mandatory/game/init/c3d_init_images.c
	srcs_mandatory/game/init/c3d_init_mlx.c
	srcs_mandatory/game/init/c3d_init_player.c
	srcs_mandatory/game/init/c3d_init_textures.c
	srcs_mandatory/game/loop/display/raycasting/c3d_raycasting_display.c
	srcs_mandatory/game/loop/display/raycasting/c3d_raycasting_getwall.c
	srcs_mandatory/game/loop/display/raycasting/c3d_raycasting.c
	srcs_mandatory/game/loop/display/raycasting/c3d_default_display.c
	srcs_mandatory/game/loop/update/default/c3d_default_update.c
	srcs_mandatory/game/loop/update/default/c3d_minimap_update.c
	srcs_mandatory/game/loop/update/default/c3d_player_collide.c
	srcs_mandatory/game/loop/update/default/c3d_player_update.c
	srcs_mandatory/game/loop/c3d_loop.c
	srcs_mandatory/game/c3d_start.c
	srcs_mandatory/parsing/c3d_parsing_check.c
	srcs_mandatory/parsing/c3d_parsing_readfile.c
	srcs_mandatory/parsing/c3d_parsing_set.c
	srcs_mandatory/parsing/c3d_parsing_square_map.c
	srcs_mandatory/parsing/c3d_parsing_utils.c
	srcs_mandatory/parsing/c3d_parsing.c
	srcs_mandatory/utils/c3d_clean.c
	srcs_mandatory/utils/c3d_error.c
	srcs_mandatory/utils/c3d_init_image.c
	srcs_mandatory/utils/c3d_math.c
	srcs_mandatory/utils/c3d_math2.c
	
endef
SRCS := $(strip $(SRCS))

define SRCS_BONUS :=
	srcs_bonus/main.c
	srcs_bonus/game/event/c3d_default_event_mouse.c
	srcs_bonus/game/event/c3d_default_event.c
	srcs_bonus/game/event/c3d_event_mouse.c
	srcs_bonus/game/event/c3d_event.c
	srcs_bonus/game/event/c3d_menu_event_mouse.c
	srcs_bonus/game/event/c3d_menu_event.c
	srcs_bonus/game/event/c3d_openclose_menu.c
	srcs_bonus/game/init/c3d_init_game.c
	srcs_bonus/game/init/c3d_init_images.c
	srcs_bonus/game/init/c3d_init_menu.c
	srcs_bonus/game/init/c3d_init_mlx.c
	srcs_bonus/game/init/c3d_init_player.c
	srcs_bonus/game/init/c3d_init_textures.c
	srcs_bonus/game/loop/display/menu/c3d_display_button.c
	srcs_bonus/game/loop/display/menu/c3d_display_checkbox.c
	srcs_bonus/game/loop/display/menu/c3d_display_keyinput.c
	srcs_bonus/game/loop/display/menu/c3d_display_numinput.c
	srcs_bonus/game/loop/display/menu/c3d_display_slidebar.c
	srcs_bonus/game/loop/display/menu/c3d_display_textinput.c
	srcs_bonus/game/loop/display/menu/c3d_menu_display.c
	srcs_bonus/game/loop/display/raycasting/c3d_default_display.c
	srcs_bonus/game/loop/display/raycasting/c3d_raycasting_display.c
	srcs_bonus/game/loop/display/raycasting/c3d_raycasting_getwall.c
	srcs_bonus/game/loop/display/raycasting/c3d_raycasting.c
	srcs_bonus/game/loop/update/default/c3d_default_update.c
	srcs_bonus/game/loop/update/default/c3d_minimap_update.c
	srcs_bonus/game/loop/update/default/c3d_player_collide.c
	srcs_bonus/game/loop/update/default/c3d_player_update.c
	srcs_bonus/game/loop/update/menu/c3d_draw_button.c
	srcs_bonus/game/loop/update/menu/c3d_draw_checkbox.c
	srcs_bonus/game/loop/update/menu/c3d_draw_keyinput.c
	srcs_bonus/game/loop/update/menu/c3d_draw_numinput.c
	srcs_bonus/game/loop/update/menu/c3d_draw_scrollbar.c
	srcs_bonus/game/loop/update/menu/c3d_draw_slidebar.c
	srcs_bonus/game/loop/update/menu/c3d_draw_textinput.c
	srcs_bonus/game/loop/update/menu/c3d_menu_update.c
	srcs_bonus/game/loop/c3d_loop.c
	srcs_bonus/game/c3d_start.c
	srcs_bonus/map_generator/mzg_clean.c
	srcs_bonus/map_generator/mzg_fillmap_check.c
	srcs_bonus/map_generator/mzg_fillmap.c
	srcs_bonus/map_generator/mzg_generator.c
	srcs_bonus/map_generator/mzg_get_maze.c
	srcs_bonus/map_generator/mzg_makemaze.c
	srcs_bonus/map_generator/mzg_makeshape.c
	srcs_bonus/map_generator/mzg_post_player.c
	srcs_bonus/map_generator/mzg_printmaze.c
	srcs_bonus/map_generator/mzg_standardize.c
	srcs_bonus/menu/c3d_button_exit.c
	srcs_bonus/menu/c3d_button_resume.c
	srcs_bonus/menu/c3d_checkbox_color.c
	srcs_bonus/menu/c3d_checkbox_invertmouse.c
	srcs_bonus/menu/c3d_checkbox_invertscroll.c
	srcs_bonus/menu/c3d_checkbox_showfps.c
	srcs_bonus/menu/c3d_keyinput_backward.c
	srcs_bonus/menu/c3d_keyinput_forward.c
	srcs_bonus/menu/c3d_keyinput_left.c
	srcs_bonus/menu/c3d_keyinput_right.c
	srcs_bonus/menu/c3d_numinput_ceil.c
	srcs_bonus/menu/c3d_numinput_floor.c
	srcs_bonus/menu/c3d_scrollbar.c
	srcs_bonus/menu/c3d_slidebar_camspeedx.c
	srcs_bonus/menu/c3d_slidebar_camspeedy.c
	srcs_bonus/menu/c3d_slidebar_fov.c
	srcs_bonus/menu/c3d_slidebar_resolution.c
	srcs_bonus/menu/c3d_slidebar_scrollspeed.c
	srcs_bonus/menu/c3d_textinput_east.c
	srcs_bonus/menu/c3d_textinput_north.c
	srcs_bonus/menu/c3d_textinput_south.c
	srcs_bonus/menu/c3d_textinput_west.c
	srcs_bonus/parsing/c3d_parsing_check.c
	srcs_bonus/parsing/c3d_parsing_readfile.c
	srcs_bonus/parsing/c3d_parsing_set.c
	srcs_bonus/parsing/c3d_parsing_square_map.c
	srcs_bonus/parsing/c3d_parsing_utils.c
	srcs_bonus/parsing/c3d_parsing.c
	srcs_bonus/utils/c3d_clean.c
	srcs_bonus/utils/c3d_color.c
	srcs_bonus/utils/c3d_error.c
	srcs_bonus/utils/c3d_init_image.c
	srcs_bonus/utils/c3d_math.c
	srcs_bonus/utils/c3d_math2.c
	srcs_bonus/utils/c3d_menu_utils.c
	srcs_bonus/utils/c3d_menu_utils2.c
	srcs_bonus/utils/c3d_menu_utils3.c
	srcs_bonus/utils/c3d_menu_utils4.c
	srcs_bonus/utils/c3d_time.c

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

SRCS_DIR := srcs_mandatory
SRCS_BONUS_DIR := srcs_bonus
OBJS_DIR := objs
LIBS_INCS_DIR := include/libs
HDRS_INCS_DIR := include/mandatory
HDRS_INCS_DIR_BONUS := include/bonus
INCS	:= -I$(LIBS_INCS_DIR) -I$(HDRS_INCS_DIR) -I$(HDRS_INCS_DIR_BONUS)
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
OBJ_FILES_BONUS := $(patsubst %.c,$(OBJS_DIR)/%.o, $(SRCS_BONUS))
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

bonus:  m_bonus
.PHONY: bonus

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

$(NAME): Makefile $(LIBS) $(OBJ_FILES)
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) -lXext -lX11 -lm

m_bonus: Makefile $(LIBS) $(OBJ_FILES_BONUS)
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES_BONUS) $(LIBS) -lXext -lX11 -lm

$(OBJS_DIR)/%.o: %.c  start_compiling
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
