#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dlouise <davidlouiz@gmail.com>             +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/09/12 02:05:18 by dlouise           #+#    #+#             *#
#*   Updated: 2015/09/23 21:59:08 by dlouise          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

.PHONY : clean, fclean, re
.SUFFIXES :

NAME = fillit

SRC =	chargement_pieces.c\
		initialisation_grille.c\
		main.c\
		resolution.c\
		uniformisation_tetriminos.c\
		verification_parametre.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -lft -L. -Wall -Werror -Wextra -o $@

%.o : %.c
	gcc -c $^ -Wall -Werror -Wextra -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
