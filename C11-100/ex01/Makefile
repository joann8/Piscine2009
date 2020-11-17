
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 15:07:02 by jacher            #+#    #+#              #
#    Updated: 2020/09/22 18:14:02 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

HDRS = includes

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -I${HDRS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HDRS}/ft.h
			ar rc ${NAME} ${OBJS}		

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
