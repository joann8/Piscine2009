
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacher <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 15:07:02 by jacher            #+#    #+#              #
#    Updated: 2020/09/24 21:01:12 by jacher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main_display_file.c 

OBJS = ${SRCS:.c=.o}


NAME = ft_display_file

CC = gcc

FLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
			${CC} ${FLAGS} -o ${NAME} ${OBJS}		

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
