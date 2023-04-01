# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiaz-ru <sdiaz-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 15:19:51 by sdiaz-ru          #+#    #+#              #
#    Updated: 2023/04/01 13:58:08 by sdiaz-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CFLAGS			=	-Wall -Werror -Wextra -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
RM				=	rm -fr
INCLUDE			=	so_long.h Get_Next_Line/get_next_line.h
DIR_MAKE_MLX	=	./MLX42
SRC				=	main.c so_long_utils.c Get_Next_Line/get_next_line.c	\
					Get_Next_Line/get_next_line_utils.c init_so_long.c		\
					paint_map.c read_map.c

all: $(NAME)

make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	make_mlx
			@gcc $(CFLAGS) $(SRC) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a
			@echo So_long compilado

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(RM) $(NAME)
			@echo Todo limpio

.PHONY: 	all make_mlx re clean fclean
