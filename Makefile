# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 15:37:46 by fnichola          #+#    #+#              #
#    Updated: 2021/10/06 10:48:50 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = includes/ft_printf.h

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c \
	srcs/ft_print_unum.c \
	srcs/ft_print_num.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT_LIB)
	cp $(LIBFT_LIB) $(NAME)
	ar rs $(NAME) $(OBJS)

$(LIBFT_LIB): force_look
	$(MAKE) -C $(LIBFT_DIR)

force_look: ;

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus so force_look
