# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkraikua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 12:46:29 by tkraikua          #+#    #+#              #
#    Updated: 2022/02/25 12:46:29 by tkraikua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf_utils.c \
		srcs/ft_printf_utils2.c \
		srcs/ft_printf.c
OBJS = $(SRCS:.c=.o)
LIB = ar -rcs
FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
		$(LIB) $(NAME) $(OBJS)

$(OBJS): %.o: %.c
		gcc $(FLAGS) -c $< -o $@ -I includes/

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all