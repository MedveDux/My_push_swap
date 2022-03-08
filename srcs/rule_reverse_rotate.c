/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:25:52 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/08 19:52:21 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reverse_rotate(t_list **a)
{
	t_list	*before_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	before_last = *a;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	before_last->next->next = (*a);
	(*a) = before_last->next;
	before_last->next = NULL;
}

void	rra(t_stacks *ps)
{
	reverse_rotate(&ps->a);
	write (1, "rra\n", 4);
}

void	rrb(t_stacks *ps)
{
	reverse_rotate(&ps->b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stacks *ps)
{
	reverse_rotate(&ps->a);
	reverse_rotate(&ps->b);
	write (1, "rrr\n", 4);
}
