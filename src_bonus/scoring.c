/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:18:36 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/19 19:25:10 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

int	max_abs(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	return (abs(b));
}

int	num_optim(int a1, int b1)
{
	if (a1 * b1 > 0)
		return (max_abs(a1, b1));
	return (abs(a1) + abs(b1));
}

int	analyzer_a(t_stacks *ps, int value_b)
{
	t_list	*prev;
	t_list	*next;
	int		count;

	count = 0;
	prev = ft_lstlast(ps->a);
	next = ps -> a;
	while (next && (*(int *)prev->content > value_b \
	|| *(int *)next->content < value_b))
	{
		count++;
		next = next->next;
		if (prev->next == NULL)
			prev = ps->a;
		else
			prev = prev->next;
	}
	return (count);
}

int	scoring(t_stacks *ps, t_list *e, int i)
{
	t_score_tmp	tmp;

	tmp.ra_score = analyzer_a(ps, *(int *)e->content);
	tmp.rra_score = ps->size_a - tmp.ra_score;
	tmp.rb_score = i;
	tmp.rrb_score = ps->size_b - i;
	e->a_score = -tmp.ra_score;
	e->b_score = -tmp.rb_score;
	if (max_abs(tmp.rra_score, tmp.rrb_score) < max_abs(e->a_score, e->b_score))
	{
		e->a_score = tmp.rra_score;
		e->b_score = tmp.rrb_score;
	}
	if ((tmp.ra_score + tmp.rrb_score) < max_abs(e->a_score, e->b_score))
	{
		e->a_score = -tmp.ra_score;
		e->b_score = tmp.rrb_score;
	}
	if ((tmp.rra_score + tmp.rb_score) < num_optim(e->a_score, e->b_score))
	{
		e->a_score = tmp.rra_score;
		e->b_score = -tmp.rb_score;
	}
	return (num_optim(e->a_score, e->b_score));
}
