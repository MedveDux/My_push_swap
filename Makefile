NAME	=	push_swap
SRC 	=	src/push_swap.c src/rule_push.c src/rule_reverse_rotate.c\
			src/rule_rotate.c src/rule_swap.c src/sort_five.c src/sort_three.c\
			src/sort.c src/scoring.c src/ft_full_array.c src/push_swap_cheaker.c src/add_main.c
SRC_LIBFT=	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c libft/ft_lstclear.c \
			libft/ft_lstlast.c libft/ft_lstnew.c \
			libft/ft_lstsize.c libft/ft_memset.c libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strlcpy.c\
			libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_substr.c
OBJS	=	$(SRC:.c=.o) 
HEAD	=	headers/push_swap.h
HEAD_LIBFT = libft/libft.h
LIBNAME	=	libft/libft.a
GCC		=	cc -Wall -Wextra -Werror -MMD
RM		=	rm -f
%.o:	%.c	Makefile $(HEAD)  
	$(GCC) -c $< -o $@
$(NAME):	$(OBJS) $(LIBNAME) $(HEAD)
	$(GCC) $(OBJS) $(LIBNAME) -o $(NAME)

all:	$(NAME)
$(LIBNAME):	$(HEAD_LIBFT) $(SRC_LIBFT)
	make -C libft

clean:
	make clean -C libft 
	$(RM) $(OBJS)
	$(RM) $(wildcard src/*.d)

fclean:	clean
	make fclean -C libft 
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
include ${wildcard src/*.d}