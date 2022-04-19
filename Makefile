# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/04/19 10:31:24 by afonso           ###   ########.fr        #
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
CFLAGS := -D BUFFER_SIZE=15
RM = rm -f

 all:
	${CC} ${FLAGS} ${SRCS} -I.

bonus: ${OBJS} ${BONUS_OBJS}
		${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.${HEADER}

test:
	${CC} ${CFLAGS} gnl_tester.c ${SRCS} -I.
	mv a.out tester
	./tester
clean:
	${RM} ${OBJS}
	${RM} tester

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
