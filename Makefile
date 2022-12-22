# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ip <ip@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 15:25:32 by aplank            #+#    #+#              #
#    Updated: 2022/12/22 12:38:25 by ip               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MY_SOURCES = check.c main.c map_check.c map.c movement.c textures.c window_handling.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(MAKE) bonus -C libft
	@$(CC) $(MY_OBJECTS) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)
#	 -lz
	@echo making mandatory .o files
	@echo starting program
#	@./so_long
	@echo
#	@make fclean
	@echo program end

$(MY_OBJECTS): 
	cc -c -Wall -Werror -Wextra $(MY_SOURCES)

clean:
	@rm -f $(MY_OBJECTS)
	@echo all .o-files deleted

fclean: clean
	@rm -f so_long
	make fclean -C libft
	@echo
	@echo ...and the so_long too

re: fclean all