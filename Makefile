# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 14:00:56 by kahmada           #+#    #+#              #
#    Updated: 2023/12/16 01:31:20 by kahmada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
cc = cc
header = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
srcs = ft_printf_hexnum.c\
		ft_printf_integers.c\
		ft_printf_ptr.c\
		ft_printf_unsigned_integers.c\
		ft_printf.c\
		fonctions_helfen.c\
		ft_putnbru_ft_putnbr.c
		
objs = $(srcs:.c=.o)

all: $(NAME)

%.o: %.c $(header)
	$(cc) $(CFLAGS) -o $@ -c $<

$(NAME): $(objs)
	ar rc $(NAME) $(objs)

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(NAME)

re: fclean all


