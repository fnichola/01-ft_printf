# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 15:37:46 by fnichola          #+#    #+#              #
#    Updated: 2021/10/05 17:05:19 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c \
	srcs/ft_print_unum.c \
	srcs/ft_print_num.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB): force_look
	$(MAKE) -C $(LIBFT_DIR)

force_look:
	@true

$(NAME): $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)
	ar rs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus so force_look
