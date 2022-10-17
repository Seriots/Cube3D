NAME := cub3D
CFLAGS := 
CC := cc
MAKE = /bin/make --no-print-directory

define SRCS :=
		main.c
		game/event/menu_event/checkbox_event.c
		game/event/menu_event/keyinput_event.c
		game/event/menu_event/numinput_event.c
		game/event/menu_event/slidebar_event.c
		game/event/menu_event/textinput_event.c
		game/event/menu_event/mapinput_event.c
		game/event/menu_event/multichoice_event.c
		game/event/menu_event/seed_event.c
		game/event/c3d_default_event_mouse.c
		game/event/c3d_default_event.c
		game/event/c3d_event_mouse.c
		game/event/c3d_event.c
		game/event/c3d_menu_event_mouse.c
		game/event/c3d_menu_event.c
		game/event/c3d_player_action.c
		game/event/c3d_startscreen_event_mouse.c
		game/event/c3d_startscreen_event.c
		game/init/objects/c3d_obj_init.c
		game/init/objects/c3d_init_door.c
		game/init/objects/c3d_init_endoor.c
		game/init/objects/c3d_init_key.c
		game/init/objects/c3d_init_lamp.c
		game/init/objects/c3d_init_heal.c
		game/init/objects/c3d_init_fullheal.c
		game/init/objects/c3d_init_energy.c
		game/init/objects/c3d_init_benergy.c
		game/init/objects/c3d_init_bonushp.c
		game/init/c3d_init_game.c
		game/init/c3d_init_images.c
		game/init/c3d_init_menu.c
		game/init/c3d_init_mlx.c
		game/init/c3d_init_player.c
		game/init/c3d_init_textures.c
		game/init/c3d_load_screen.c
		game/init/c3d_save_settings_load.c
		game/init/c3d_save_settings.c
		game/loop/display/menu/c3d_display_button.c
		game/loop/display/menu/c3d_display_checkbox.c
		game/loop/display/menu/c3d_display_keyinput.c
		game/loop/display/menu/c3d_display_numinput.c
		game/loop/display/menu/c3d_display_slidebar.c
		game/loop/display/menu/c3d_display_textinput.c
		game/loop/display/menu/c3d_display_multichoice.c
		game/loop/display/menu/c3d_menu_display.c
		game/loop/display/start_screen/c3d_display_seed.c
		game/loop/display/start_screen/c3d_startscreen_display.c
		game/loop/display/raycasting/c3d_bar_display.c
		game/loop/display/raycasting/c3d_default_display.c
		game/loop/display/raycasting/c3d_hand_display.c
		game/loop/display/raycasting/c3d_inventory_display.c
		game/loop/display/raycasting/c3d_raycasting_display.c
		game/loop/display/raycasting/c3d_raycasting_getwall.c
		game/loop/display/raycasting/c3d_raycasting.c
		game/loop/update/default/c3d_default_update.c
		game/loop/update/default/c3d_minimap_update.c
		game/loop/update/default/c3d_player_collide.c
		game/loop/update/default/c3d_player_update.c
		game/loop/update/default/c3d_next_stage.c
		game/loop/update/default/c3d_objects_update.c
		game/loop/update/menu/c3d_draw_button.c
		game/loop/update/menu/c3d_draw_checkbox.c
		game/loop/update/menu/c3d_draw_keyinput.c
		game/loop/update/menu/c3d_draw_multichoice.c
		game/loop/update/menu/c3d_draw_numinput.c
		game/loop/update/menu/c3d_draw_scrollbar.c
		game/loop/update/menu/c3d_draw_slidebar.c
		game/loop/update/menu/c3d_draw_textinput.c
		game/loop/update/menu/c3d_menu_update.c
		game/loop/update/start_screen/c3d_startscreen_update.c
		game/loop/update/start_screen/c3d_draw_seed.c
		game/loop/c3d_loop.c
		game/c3d_start.c
		menu/settings/c3d_button_exit.c
		menu/settings/c3d_button_resume.c
		menu/settings/c3d_checkbox_color.c
		menu/settings/c3d_checkbox_invertmouse.c
		menu/settings/c3d_checkbox_invertscroll.c
		menu/settings/c3d_checkbox_showfps.c
		menu/settings/c3d_checkbox_showmmap.c
		menu/settings/c3d_checkbox_showseed.c
		menu/settings/c3d_keyinput_backward.c
		menu/settings/c3d_keyinput_drop.c
		menu/settings/c3d_keyinput_run.c
		menu/settings/c3d_keyinput_crouch.c
		menu/settings/c3d_keyinput_forward.c
		menu/settings/c3d_keyinput_interact.c
		menu/settings/c3d_keyinput_left.c
		menu/settings/c3d_keyinput_right.c
		menu/settings/c3d_keyinput_slot1.c
		menu/settings/c3d_keyinput_slot2.c
		menu/settings/c3d_keyinput_slot3.c
		menu/settings/c3d_keyinput_slot4.c
		menu/settings/c3d_keyinput_slot5.c
		menu/settings/c3d_keyinput_slot6.c
		menu/settings/c3d_keyinput_slot7.c
		menu/settings/c3d_keyinput_slot8.c
		menu/settings/c3d_numinput_ceil.c
		menu/settings/c3d_numinput_floor.c
		menu/settings/c3d_scrollbar.c
		menu/settings/c3d_slidebar_camspeedx.c
		menu/settings/c3d_slidebar_camspeedy.c
		menu/settings/c3d_slidebar_fov.c
		menu/settings/c3d_slidebar_fps.c
		menu/settings/c3d_slidebar_resolution.c
		menu/settings/c3d_slidebar_scrollspeed.c
		menu/settings/c3d_textinput_east.c
		menu/settings/c3d_textinput_north.c
		menu/settings/c3d_textinput_south.c
		menu/settings/c3d_textinput_west.c
		menu/start/c3d_multichoice_difficulty.c
		menu/start/c3d_button_quit.c
		menu/start/c3d_button_play.c
		menu/start/c3d_seed.c
		menu/start/c3d_mapinput_mappath.c
		parsing/c3d_parsing_check.c
		parsing/c3d_parsing_getelem.c
		parsing/c3d_parsing_readfile.c
		parsing/c3d_parsing_set.c
		parsing/c3d_parsing_square_map.c
		parsing/c3d_parsing_utils.c
		parsing/c3d_parsing.c
		utils/c3d_clean.c
		utils/c3d_clean2.c
		utils/c3d_color.c
		utils/c3d_error.c
		utils/c3d_event_utils.c
		utils/c3d_game_error.c
		utils/c3d_init_image.c
		utils/c3d_inventory_utils.c
		utils/c3d_math.c
		utils/c3d_math2.c
		utils/c3d_menu_utils.c
		utils/c3d_menu_utils2.c
		utils/c3d_menu_utils3.c
		utils/c3d_menu_utils4.c
		utils/c3d_menu_utils5.c
		utils/c3d_menu_utils6.c
		utils/c3d_save_utils.c
		utils/c3d_time.c
		map_generator/mzg_generator.c
		map_generator/mzg_clean.c
		map_generator/mzg_fillmap_check.c
		map_generator/mzg_fillmap.c
		map_generator/mzg_makemaze.c
		map_generator/mzg_makedoor.c
		map_generator/mzg_makeshape.c
		map_generator/mzg_printmaze.c
		map_generator/mzg_standardize.c
		map_generator/mzg_openmaze_check.c
		map_generator/mzg_openmaze.c
		map_generator/mzg_generate_player.c
		map_generator/mzg_generatekey.c

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
	$(LIB_DIR)/ft_printf/libft_printf.a
	$(LIB_DIR)/ft/libft.a
	$(LIB_DIR)/list/liblist.a
	$(LIB_DIR)/tree/libtree.a
	$(LIB_DIR)/mlx/libmlx_Linux.a
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
