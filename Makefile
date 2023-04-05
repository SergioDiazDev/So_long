# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 15:19:51 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/04/06 00:03:24 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif
RM				=	rm -fr
INCLUDE			=	so_long.h Get_Next_Line/get_next_line.h
DIR_MAKE_MLX	=	./MLX42
DIR_SRC			=	./src/
DIR_GNL			=	./Get_Next_Line/
SRC				=	$(DIR_SRC)so_long.c $(DIR_SRC)so_long_utils.c 	$(DIR_SRC)init_so_long.c\
					$(DIR_SRC)paint_map.c $(DIR_SRC)read_map.c $(DIR_SRC)correct_map.c $(DIR_SRC)hooks.c\
					$(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c

OBJ				=	$(SRC:.c=.o)

all: make_mlx $(NAME)

make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	$(OBJ)
			@gcc $(SRC) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a $(CFLAGS)
			@echo So_long compilado

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)
		@$(RM) $(OBJ)

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(RM) $(NAME) 
			@echo Todo limpio

.PHONY: 	all make_mlx re clean fclean
