# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 09:54:22 by mvan-eyn          #+#    #+#              #
#    Updated: 2020/11/24 09:06:00 by mvan-eyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strcmp.s ft_strlen.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s
OBJS		=	$(SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-f elf64
FLAGS		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)
				rm -rf a.out

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(NAME) main.c
				@./a.out
				@rm -rf a.out

