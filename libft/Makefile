# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 19:03:07 by cyelena           #+#    #+#              #
#    Updated: 2022/02/23 17:40:08 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strlen.c ft_strjoin.c ft_atoi.c ft_split.c ft_substr.c\
		ft_strdup.c ft_strlcpy.c ft_putstr_fd.c ft_putchar_fd.c ft_isdigit.c

HEAD = libft.h

OBJ = ${patsubst %.c,%.o,$(SRCS)}


CC = gcc
FLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c ${HEAD} Makefile
	${CC} ${FLAGS} ${OPTFLAGS} -c $< -o $@ 
		
clean:
	${RM} ${OBJ} 


fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re