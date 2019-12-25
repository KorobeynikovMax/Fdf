# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedavis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 11:05:54 by bedavis           #+#    #+#              #
#    Updated: 2019/12/23 11:06:58 by bedavis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = example

SRC = example.c keyboard.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx
	mv minilibx/libmlx.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C minilibx clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C minilibx clean
	rm -rf $(NAME)

re : fclean all
