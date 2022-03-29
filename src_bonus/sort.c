/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:47:49 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/29 19:04:53 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pb_in_b_full(t_stacks *ps, t_median *data)
{
	t_list	*head;
	int		i;

	i = data->median;
	head = ps->a;
	while (ps->size_a > 3)
	{
		if (*(int *)head->content != data->min
			&& *(int *)head->content != data->max
			&& *(int *)head->content != data->median)
		{
			pb(ps, 1);
			if (*(int *)ps->b->content < i)
				rb(ps, 1);
		}
		else
			ra(ps, 1);
		head = ps->a;
	}
}

void	final_rotate(t_stacks *ps, t_median *data)
{
	t_list	*tmp;
	int		i;

	tmp = ps->a;
	i = 0;
	while (tmp && *(int *)tmp->content != data->min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < (ps->size_a - i))
		while (i--)
			ra(ps, 1);
	else
	{
		i = ps->size_a - i;
		while (i--)
			rra(ps, 1);
	}
}

void	rotator(t_stacks *ps, t_list *min)
{
	while (min->b_score > 0 && min->a_score > 0
		&& min->a_score-- && min->b_score--)
		rrr(ps, 1);
	while (min->a_score < 0 && min->b_score < 0
		&& min->a_score++ && min->b_score++)
		rr(ps, 1);
	while (min->a_score < 0 && min->a_score++)
		ra(ps, 1);
	while (min->b_score > 0 && min->b_score--)
		rrb(ps, 1);
	while (min->a_score > 0 && min->a_score--)
		rra(ps, 1);
	while (min->b_score < 0 && min->b_score++)
		rb(ps, 1);
}

void	sort_util(t_stacks *ps)
{
	int		i;
	int		num_optomize;
	t_list	*min;
	t_list	*tmp;

	while (ps->size_b > 0)
	{
		i = 0;
		tmp = ps->b;
		min = tmp;
		num_optomize = scoring(ps, tmp, i);
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
			if (num_optomize > scoring(ps, tmp, i))
			{
				min = tmp;
				num_optomize = scoring(ps, tmp, i);
			}
		}
		rotator(ps, min);
		pa(ps, 1);
	}
}

void	sort(t_stacks *ps, t_median *data)
{
	if (ps->size_a >= 5)
	{
		pb_in_b_full(ps, data);
		ft_presort_three(ps);
		sort_util(ps);
		final_rotate(ps, data);
	}
}
