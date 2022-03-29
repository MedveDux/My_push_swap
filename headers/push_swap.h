/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:06:40 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/29 19:03:31 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_median
{
	int	max;
	int	min;
	int	median;
}	t_median;

typedef struct s_stacks
{
	t_list			*a;
	t_list			*b;
	int				size;
	int				size_a;
	int				size_b;
	int				*array;
}	t_stacks;

typedef struct s_score_tmp
{
	int	ra_score;
	int	rra_score;
	int	rb_score;
	int	rrb_score;
}	t_score_tmp;
void	ft_clear(int **array);
void	error(void);

int		ft_count(char **argv);
void	ft_sort_array(int *array, int argc);
void	ft_not_repeat(int k, int *array);
void	initilization(int *i, int **array, int *flag, int *count);
void	if_sent(int *i, int *j, char **sent_array, int *array);
int		*ft_full_array(int count, char **argv);
void	ft_median(int *array, int count, t_median *data);
void	ft_stacks(t_stacks *ps, int *array);
void	sorter(t_stacks *ps, t_median *data);
int		ft_cheaking_for_sortint(t_stacks *ps);
// rule
void	push(t_list **src, t_list **dest);
void	pb(t_stacks	*ps, int i);
void	pa(t_stacks	*ps, int i);
void	reverse_rotate(t_list **a);
void	rra(t_stacks *ps, int i);
void	rrb(t_stacks *ps, int i);
void	rrr(t_stacks *ps, int i);
void	rotate(t_list **a);
void	ra(t_stacks *ps, int i);
void	rb(t_stacks *ps, int i);
void	rr(t_stacks *ps, int i);
void	swap(t_list **a);
void	sa(t_stacks *ps, int i);
void	sb(t_stacks *ps, int i);
void	ss(t_stacks *ps, int i);
//sort three 3
void	ft_presort_three(t_stacks *ps);
void	ft_three(t_stacks *ps);
//sort five 5
void	ft_five(t_stacks *ps);
//sort
void	pb_in_b_full(t_stacks *ps, t_median *data);
void	final_rotate(t_stacks *ps, t_median *data);
void	rotator(t_stacks *ps, t_list *min);
void	sort_util(t_stacks *ps);
void	sort(t_stacks *ps, t_median *data);
//scoring
int		abs(int c);
int		max_abs(int a, int b);
int		num_optim(int a1, int b1);
int		analyzer_a(t_stacks *ps, int value_b);
int		scoring(t_stacks *ps, t_list *e, int i);
#endif