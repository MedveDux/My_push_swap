/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:06:40 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/18 18:31:01 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
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
void	error(void);
// rule
void	push(t_list **src, t_list **dest);
void	pb(t_stacks	*ps);
void	pa(t_stacks	*ps);
void	reverse_rotate(t_list **a);
void	rra(t_stacks *ps);
void	rrb(t_stacks *ps);
void	rrr(t_stacks *ps);
void	rotate(t_list **a);
void	ra(t_stacks *ps);
void	rb(t_stacks *ps);
void	rr(t_stacks *ps);
void	swap(t_list **a);
void	sa(t_stacks *ps);
void	sb(t_stacks *ps);
void	ss(t_stacks *ps);
//sort three 3
void	ft_presort_three(t_stacks *ps);
void	ft_three(t_stacks *ps);
//sort five 5
void	ft_five(t_stacks *ps, t_median data);

#endif