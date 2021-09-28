# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 15:37:46 by fnichola          #+#    #+#              #
#    Updated: 2021/09/28 17:10:43 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT_DIR = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c \
	srcs/ft_print_unum.c \
	srcs/ft_print_num.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

libft:
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) libft
	mv $(LIBFT_DIR)/libft.a $(NAME)
	ar rs $(NAME) $(OBJS)

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus test so libft
