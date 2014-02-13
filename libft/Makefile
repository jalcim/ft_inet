#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 22:52:49 by jalcim            #+#    #+#              #
#    Updated: 2013/12/25 09:01:22 by jalcim           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_atoi.c		ft_isprint.c	ft_memcpy.c		ft_putendl.c \
	ft_strdel.c		ft_strlcat.c	ft_strncpy.c	ft_strstr.c \
	ft_bzero.c		ft_itoa.c		ft_memdel.c		ft_putendl_fd.c \
	ft_strlen.c		ft_strnequ.c	ft_strsub.c		ft_strchr.c \
	ft_isalnum.c	ft_memalloc.c	ft_memmove.c	ft_putnbr.c \
	ft_strequ.c		ft_strmap.c		ft_strnew.c		ft_strtrim.c \
	ft_isalpha.c	ft_memccpy.c	ft_memset.c		ft_putnbr_fd.c \
	ft_striter.c	ft_strmapi.c	ft_strnstr.c	ft_tolower.c \
	ft_isascii.c	ft_memchr.c		ft_putchar.c	ft_strcmp.c \
	ft_striteri.c	ft_strncat.c	ft_strrchr.c	ft_toupper.c \
	ft_isdigit.c	ft_memcmp.c		ft_putchar_fd.c	ft_putstr.c \
	ft_strncmp.c	ft_strsplit.c	ft_strcat.c		ft_strdup.c \
	ft_strclr.c		ft_strcpy.c		ft_strjoin.c	ft_putstr_fd.c \
	ft_realloc.c	ft_strlcar.c	ft_printf.c		ft_strrcpy.c \
	ft_strrncpy.c	ft_strrlcar.c	ft_rbzero.c

OBJ =  ft_atoi.o	ft_isprint.o	ft_memcpy.o		ft_putendl.o \
	ft_strdel.o		ft_strlcat.o	ft_strncpy.o	ft_strstr.o \
	ft_bzero.o		ft_itoa.o		ft_memdel.o		ft_putendl_fd.o \
	ft_strlen.o		ft_strnequ.o	ft_strsub.o		ft_strchr.o \
	ft_isalnum.o	ft_memalloc.o	ft_memmove.o	ft_putnbr.o \
	ft_strequ.o		ft_strmap.o		ft_strnew.o		ft_strtrim.o \
	ft_isalpha.o	ft_memccpy.o	ft_memset.o		ft_putnbr_fd.o \
	ft_striter.o	ft_strmapi.o	ft_strnstr.o	ft_tolower.o \
	ft_isascii.o	ft_memchr.o		ft_putchar.o	ft_strcmp.o \
	ft_striteri.o	ft_strncat.o	ft_strrchr.o	ft_toupper.o \
	ft_isdigit.o	ft_memcmp.o		ft_putchar_fd.o	ft_putstr.o \
	ft_strncmp.o	ft_strsplit.o	ft_strcat.o		ft_strdup.o \
	ft_strclr.o		ft_strcpy.o		ft_strjoin.o	ft_putstr_fd.o \
	ft_realloc.o	ft_strlcar.o	ft_printf.o		ft_strrcpy.o \
	ft_strrncpy.o	ft_strrlcar.o	ft_rbzero.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)


$(NAME):
	gcc $(FLAGS) -c $(SRC) -I .
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
