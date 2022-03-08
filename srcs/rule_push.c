/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:46:43 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/08 18:57:55 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp);
}

void	pb(t_stacks	*ps)
{
	ps->size_a -= 1;
	ps->size_b += 1;
	push(&ps->a, &ps->b);
	write(1, "pb\n", 3);
}

void	pa(t_stacks	*ps)
{
	ps->size_a += 1;
	ps->size_b -= 1;
	push(&ps->b, &ps->a);
	write(1, "pa\n", 3);
}
