# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttecleha <ttecleha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 18:27:45 by ttecleha          #+#    #+#              #
#    Updated: 2025/11/24 18:33:02 by ttecleha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_itoa.c	ft_print_hex.c	ft_printf.c	ft_printp.c \
	  	  ft_putnbru.c	\

OBJECTS = $(SRCS:.c=.o)

NAME = libftprintf.a

INC = .

.c.o :
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all 

