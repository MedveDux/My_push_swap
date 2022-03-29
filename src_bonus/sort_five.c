/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:23:21 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/29 19:04:14 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	search_min(t_list *lst)
{
	int	steps;
	int	min;
	int	count;

	steps = 0;
	count = 0;
	min = *(int *)lst->content;
	while (lst->next != NULL)
	{
		lst = lst->next;
		steps++;
		if (*(int *)lst->content < min)
		{
			min = *(int *)lst->content;
			count = steps;
		}
	}
	return (count);
}

void	ft_five(t_stacks *ps)
{
	int	rot_score;

	while (ps->size_a > 3)
	{
		rot_score = search_min(ps->a);
		if (rot_score < ps->size_a - rot_score)
			while (rot_score--)
				ra(ps, 1);
		else
			while (ps->size_a - rot_score++ > 0)
				rra(ps, 1);
		pb(ps, 1);
	}
	ft_three(ps);
	while (ps->size_b != 0)
		pa(ps, 1);
}
