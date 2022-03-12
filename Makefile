# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/03/12 12:11:09 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = get_next_line.h
LIB = ar -rcs
SRCS =  get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
BONUS =
BONUS_OBJS = ${BONUS:.c=.o}
CC = gcc
FLAGS := -D BUFFER_SIZE=42
RM = rm -f

 all:
	${CC} ${FLAGS} ${SRCS} -I.

bonus: ${OBJS} ${BONUS_OBJS}
		${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.${HEADER}

test:${OBJS}
	${CC} ${CFLAGS} gnl_tester.c ${OBJS} -I.
	mv a.out tester
clean:
	${RM} ${OBJS}
	${RM} ${BONUS_OBJS}
	${RM} tester

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
