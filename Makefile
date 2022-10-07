
NAME				:= cub3D
MANDATORY_FOLDER	:= z_mandatory
BONUS_FOLDER		:= z_bonus
MAKE 				= /bin/make --no-print-directory

all:
	@$(MAKE) -C $(MANDATORY_FOLDER)
	@rm -f $(BONUS_FOLDER)/$(NAME)
	@cp $(MANDATORY_FOLDER)/$(NAME) .

mgen:
	@$(MAKE) -C $(BONUS_FOLDER)/srcs/map_generator
	@cp $(BONUS_FOLDER)/srcs/map_generator/gen .

bonus:
	@$(MAKE) -C $(BONUS_FOLDER)
	@rm -f $(MANDATORY_FOLDER)/$(NAME)
	@cp $(BONUS_FOLDER)/$(NAME) .

clean:
	@$(MAKE) clean -C $(MANDATORY_FOLDER)
	@$(MAKE) clean -C $(BONUS_FOLDER)

fclean:
	@$(MAKE) fclean -C $(MANDATORY_FOLDER)
	@$(MAKE) fclean -C $(BONUS_FOLDER)
	@rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
