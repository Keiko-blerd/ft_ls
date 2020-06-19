# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/24 13:24:40 by nhlatshw          #+#    #+#              #
#    Updated: 2019/07/02 17:35:23 by nhlatshw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_memset.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isalnum.c \
		ft_memcpy.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_atoi.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_isspace.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_memchr.c \
		ft_itoa.c \
		ft_strncmp.c \
		ft_strdel.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_strclr.c \
		ft_strtrim.c \
		ft_strjoin.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_strndup.c \
		ft_cntwrd.c \

OBJ = ft_isalpha.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_bzero.o \
		ft_memset.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_isalnum.o \
		ft_memcpy.o \
		ft_memcmp.o \
		ft_strlen.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_strdup.o \
		ft_atoi.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_isspace.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_strnew.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strcmp.o \
		ft_memchr.o \
		ft_itoa.o \
		ft_strncmp.o \
		ft_strdel.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strsplit.o \
		ft_strclr.o \
		ft_strtrim.o \
		ft_strjoin.o \
		ft_putendl_fd.o \
		ft_putchar_fd.o \
		ft_putendl.o \
		ft_putnbr_fd.o \
		ft_putnbr.o \
		ft_putstr_fd.o \
		ft_strndup.o \
		ft_cntwrd.o \

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) Was succesfully created"
	@ranlib $(NAME)
	@echo "$(NAME) Indexed"
	
clean:
	@rm -rf $(OBJ)
	@echo "Objects Deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) Deleted"

re: fclean all

.PHONY: all, clean, fclean, re