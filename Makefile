# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aplank <aplank@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:25:32 by aplank            #+#    #+#              #
#    Updated: 2023/01/02 20:15:30 by aplank           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MY_SOURCES = check.c main.c map_check.c map.c movement.c textures_bat.c textures.c window_handling.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(MAKE) bonus -C libft
	@make -C mlx_linux
	@$(CC) $(MY_OBJECTS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lz -lm -o $(NAME)
	@echo making mandatory .o files
	@echo starting program
	@valgrind ./so_long level_3.ber
	@echo
	@make fclean
	@echo program end

$(MY_OBJECTS): 
	cc -c -Wall -Werror -Wextra $(MY_SOURCES)

clean:
	@rm -f $(MY_OBJECTS)
	@echo all .o-files deleted

fclean: clean
	@rm -f so_long
	@make fclean -C libft
	@make clean -C mlx_linux
	@echo
	@echo ...and the so_long too

re: fclean all