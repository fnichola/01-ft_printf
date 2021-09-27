# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 21:47:42 by fnichola          #+#    #+#              #
#    Updated: 2021/09/27 21:07:03 by fnichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

TEST = libft-tests.out

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

TEST_SRC = libft_TESTS.c

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test: all bonus
	$(CC) $(CFLAGS) $(TEST_SRC) $(NAME) -g -o $(TEST)

so: $(OBJS) $(BONUS_OBJS)
	gcc -shared -o libft.so $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(BONUS_OBJS)
	$(RM) -f libft_TESTS.o
	$(RM) -f libft.so

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f $(TEST)

re: fclean all

.PHONY: all clean fclean re bonus test so
