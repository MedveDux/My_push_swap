/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:54:06 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/08 18:48:33 by cyelena          ###   ########.fr       */
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

void	sa(t_stacks *ps)
{
	swap(&ps->a);
	write (1, "sa\n", 3);
}

void	sb(t_stacks *ps)
{
	swap(&ps->b);
	write (1, "sb\n", 3);
}

void	ss(t_stacks *ps)
{
	swap(&ps->a);
	swap(&ps->b);
	write (1, "ss\n", 3);
}
