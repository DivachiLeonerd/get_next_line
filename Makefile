# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2022/05/17 13:01:27 by atereso-         ###   ########.fr        #
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
CFLAGS :=-Wall -Wextra -Werror -D BUFFER_SIZE=42 -fsanitize=address
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
