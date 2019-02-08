#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 20:38:22 by aabdulla          #+#    #+#              #
#    Updated: 2019/02/07 20:39:15 by aabdulla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1
LIBFT = -lft -L./libft/
LIBVEC = -lvec -L./libvec/
CFLAGS = -Wall -Werror -Wextra
OBJDIR	= ./obj/
SRCDIR	= ./src/
INCDIR	= ./includes/
MLX = -lmlx -framework OpenGL -framework AppKit
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

SRC =	main.c \
		parser.c \
		set_objects.c \
		split_window.c \
		render.c \
		intersect.c \
		light.c \
		key.c \
		mouse.c \

all: obj $(NAME)

obj:
	@ mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@ echo "compiling...\n"
	@ make -C libft/
	@ make -C libvec/
	@ gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBVEC) -I $(INCDIR) $(MLX)
	@ echo "done\n"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@ gcc $(CFLAGS) -I $(INCDIR) -c -o $@ $<

clean:
	@ make clean -C libft/
	@ make clean -C libvec/
	@ /bin/rm -rf $(OBJDIR)
	@ echo "clean done"

fclean: clean
	@ make fclean -C libft/
	@ make fclean -C libvec/
	@ /bin/rm -f $(NAME)
	@ echo "fclean done"

re: fclean all

.PHONY: all clean fclean re