#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 16:24:17 by aabdulla          #+#    #+#              #
#    Updated: 2019/02/08 16:24:54 by aabdulla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libvec.a
HEADER = libvec.h
OBJDIR	= ./obj/
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

SRC = 	ft_vecadd.c \
		ft_veccross.c \
		ft_vecdot.c \
		ft_veclength.c \
		ft_vecmult.c \
		ft_vecnorm.c \
		ft_vecprod.c \
		ft_vecsub.c \
		ft_vectransfor.c \

all: obj $(NAME)

obj:
	@ mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@ gcc $(CFLAGS) -I $(HEADER) -c -o $@ $^

clean:
	@ /bin/rm -rf $(OBJDIR)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re