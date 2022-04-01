NAME	=	push_swap
NAME_BONUS	= checker
SRC 	=	src/push_swap.c src/rule_push.c src/rule_reverse_rotate.c\
			src/rule_rotate.c src/rule_swap.c src/sort_five.c src/sort_three.c\
			src/sort.c src/scoring.c src/ft_full_array.c src/push_swap_cheaker.c src/add_main.c
SRC_BONUS	=	src_bonus/add_main.c src_bonus/ft_full_array.c src_bonus/push_swap_bonus.c\
				src_bonus/push_swap_cheaker.c src_bonus/rule_push.c src_bonus/rule_reverse_rotate.c\
				src_bonus/rule_rotate.c src_bonus/rule_swap.c src_bonus/scoring.c src_bonus/sort_five.c\
				src_bonus/sort_three.c src_bonus/sort.c get_next_line/get_next_line.c
SRC_LIBFT=	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c libft/ft_lstclear.c \
			libft/ft_lstlast.c libft/ft_lstnew.c \
			libft/ft_lstsize.c libft/ft_memset.c libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strlcpy.c\
			libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_substr.c
OBJS	=	$(SRC:.c=.o) 
OBJS_BONUS	=	$(SRC_BONUS:.c=.o) 
HEAD	=	headers/push_swap.h
HEAD_BONUS	=	headers/push_swap_bonus.h
HEAD_LIBFT = libft/libft.h
LIBNAME	=	libft/libft.a
GCC		=	cc -Wall -Wextra -Werror -MMD
RM		=	rm -f
%.o:	%.c	Makefile $(HEAD)  
	$(GCC) -c $< -o $@

$(NAME):	$(OBJS) $(LIBNAME) $(HEAD)
	$(RM) $(OBJS_BONUS) $(NAME_BONUS)
	$(GCC) $(OBJS) $(LIBNAME) -o $(NAME)

all:	$(NAME)

bonus 			: $(NAME_BONUS)

$(NAME_BONUS)	:	$(OBJS_BONUS) $(LIBNAME) $(HEAD_BONUS)
	$(RM) $(OBJS) $(NAME)
	$(GCC) $(OBJS_BONUS) $(LIBNAME) -o $(NAME_BONUS)


$(LIBNAME):	$(HEAD_LIBFT) $(SRC_LIBFT)
	make -C libft

clean:
	make clean -C libft 
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(wildcard src/*.d) $(wildcard src_bonus/*.d) $(wildcard get_next_line/*.d)

fclean:	clean
	make fclean -C libft 
	$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY:	all clean fclean re bonus
include ${wildcard src/*.d}