/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:58:53 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/29 19:04:01 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_presort_three(t_stacks *ps)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first > second && second < third && first < third)
		sa(ps, 1);
	else if (first > second && second > third && first > third)
		sa(ps, 1);
	else if (first < second && second > third && first < third)
		sa(ps, 1);
}

void	ft_three(t_stacks *ps)
{
	int	first;
	int	second;
	int	third;

	ft_presort_three(ps);
	first = *(int *)(ps->a->content);
	second = *(int *)(ps->a->next->content);
	third = *(int *)(ps->a->next->next->content);
	if (first < second && second > third && first > third)
		rra(ps, 1);
	else if (first > second && second < third && first > third)
		ra(ps, 1);
}
