
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 15:07:02 by jacher            #+#    #+#              #
#    Updated: 2020/09/28 15:05:25 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main_tail.c srcs/*.c

OBJS = ${SRCS:.c=.o}

NAME = ft_tail

CC = gcc

FLAGS = -Wall -Wextra -Werror

${NAME}:	 
			${CC} ${FLAGS} -o ${NAME} ${SRCS}		

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
