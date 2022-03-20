/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:08:38 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/20 21:24:58 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_list **a)
{
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = (*a);
	(*a) = (*a)->next;
	ft_lstadd_back(a, last);
	last->next = NULL;
}

void	ra(t_stacks *ps)
{
	rotate(&ps->a);
	write (1, "ra\n", 3);
}

void	rb(t_stacks *ps)
{
	rotate(&ps->b);
	write (1, "rb\n", 3);
}

void	rr(t_stacks *ps)
{
	rotate(&ps->a);
	rotate(&ps->b);
	write (1, "rr\n", 3);
}
