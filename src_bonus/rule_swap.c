/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:54:06 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/29 19:05:33 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_list **a)
{
	t_list	*tmp;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sa(t_stacks *ps, int i)
{
	swap(&ps->a);
	if (i)
		write (1, "sa\n", 3);
}

void	sb(t_stacks *ps, int i)
{
	swap(&ps->b);
	if (i)
		write (1, "sb\n", 3);
}

void	ss(t_stacks *ps, int i)
{
	swap(&ps->a);
	swap(&ps->b);
	if (i)
		write (1, "ss\n", 3);
}
