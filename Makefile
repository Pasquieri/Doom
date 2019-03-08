NAME = wolf3D

SRC = src/ft_trace_seg.c src/main.c src/put_pxl_img.c src/quadrillage.c\
	  src/color_case.c \
	  src/cercle.c src/init_env.c src/intersection.c\
	  src/detection_mur.c src/clean_img.c src/detection_mur_horizontal.c\
	  src/detection_mur_vertical.c src/pars_init.c src/affichage_mur.c\
	  src/deplacements.c src/deplacements_extra.c src/open_menu.c\
	  src/error_message.c src/verif_char.c src/compte_char.c src/wall_row.c\
	  src/wall_line.c src/tablen.c src/fill_tab.c src/malloc_tab.c\
	  src/verif_valeur.c src/recup_info_player.c src/check_file.c\
	  src/check_open_map.c src/re_pars.c src/put_texture_img.c\
	  src/init_texture.c src/motion_notify.c src/win_init.c\
	  src/rotation_regard.c src/key_press.c src/trig_press.c\
	  src/menu_off.c src/arrow_menu.c src/exec_calcul.c

HEADER = libft/libft.h include/wolf3d.h

OBJ = $(SRC:.c=.o)

COLOR = \033[1;33m
COLOR_OFF = \033[0m

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	@gcc -Wall -Werror -Wextra -I minilibx/ minilibx/libmlx.a \
		-framework OpenGL -framework AppKit \
		$(HEADER) $(SRC) libft/libft.a
	@mv a.out $(NAME)
	@echo "${COLOR}all : Wolf3D created √${COLOR_OFF}"

./%.o : src/%.c
	@gcc -Wall -Werror -Wextra -I minilibx/ minilibx/libmlx.a\
		-framework OpenGL -framework AppKit \
		-c $< -o $@ -I $(HEADER) libft/libft.a

clean :
	make -C libft clean
	make -C minilibx clean
	@rm -rf $(OBJ)
	@echo "${COLOR}Wolf3D clean √${COLOR_OFF}"

fclean : clean
	make -C libft fclean
	@rm -rf $(NAME)
	@echo "${COLOR}Wolf3D fclean √${COLOR_OFF}"

re : fclean all
