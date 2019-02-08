#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 13:51:57 by aabdulla          #+#    #+#              #
#    Updated: 2018/03/24 18:57:25 by aabdulla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
OBJDIR	= ./obj/
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

SRC =	./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memccpy.c \
		./ft_memmove.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_strlen.c \
		./ft_strdup.c \
		./ft_strcpy.c \
		./ft_strncpy.c \
		./ft_strcat.c \
		./ft_strncat.c \
		./ft_strlcat.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strstr.c \
		./ft_strnstr.c \
		./ft_strcmp.c \
		./ft_strncmp.c \
		./ft_atoi.c \
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_memalloc.c \
		./ft_memdel.c \
		./ft_strnew.c \
		./ft_strdel.c \
		./ft_strclr.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strequ.c \
		./ft_strnequ.c \
		./ft_strsub.c \
		./ft_strjoin.c \
		./ft_strtrim.c \
		./ft_strsplit.c \
		./ft_itoa.c \
		./ft_putchar.c \
		./ft_putstr.c \
		./ft_putendl.c \
		./ft_putnbr.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_lstnew.c \
		./ft_lstdelone.c \
		./ft_lstdel.c \
		./ft_lstadd.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_swap.c \
		./ft_intlen.c \
		./ft_isupper.c \
		./ft_isspace.c \
		./ft_sqrt.c \
		./get_next_line.c \
		./ft_atoi_base.c \
		./ft_abs.c \
		./ft_pow.c \
		./ft_str2del.c \
		./ft_brackets.c \
		./ft_count_printable_str.c \
		./ft_count_words.c \
		./ft_max.c \
		./ft_min.c \
		./ft_strbetween_len.c \
		./ft_strbetween_sub.c \
		./ft_strjoin_free.c \
		./ft_get_file_content.c \
		./ft_get_next_newline.c \


all: obj $(NAME)

obj:
	@ mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@ gcc $(CFLAGS) -I $(INCDIR) -c -o $@ $<

clean:
	@ /bin/rm -rf $(OBJDIR)

fclean: clean
	@ /bin/rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re