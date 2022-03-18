/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:58:53 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/13 18:47:48 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_presort_three(t_stacks *ps)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)ps->a->content;
	second = *(int *)ps->a->next->content;
	third = *(int *)ps->a->next->next->content;
	if (first > second && second > third && first < third)
		sa(ps);
	else if (first > second && second > third && first > third)
		sa(ps);
	else if (first < second && second > third && first < third)
		sa(ps);
}

void	ft_three(t_stacks *ps)
{
	int	first;
	int	second;
	int	third;

	ft_presort_three(ps);
	first = *(int *)ps->a->content;
	second = *(int *)ps->a->next->content;
	third = *(int *)ps->a->next->next->content;
	if (first < second && second > third && first > third)
		rra(ps);
	else if (first > second && second < third && first > third)
		ra(ps);
	else if (first > second && second > third && first < third)
		ra(ps);
	else if (first > second && second < third && first < third)
		sa(ps);
}
