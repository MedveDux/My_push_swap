/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:23:21 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/16 15:02:29 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_five(t_stacks *ps, t_median data)
{
	while (ps->size_a > 3)
	{
		if (*(int *)ps->a->content == data.max || \
			*(int *)ps->a->content == data.min)
			pb(ps);
		else
			ra(ps);
	}
	ft_three(ps);
	while (ps->size_b != 0)
	{
		if (*(int *)ps->b->content == data.max)
		{
			pa(ps);
			ra(ps);
		}
		else
			pa(ps);
	}
}
