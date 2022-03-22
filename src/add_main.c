/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:59:17 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/22 20:00:20 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_median(int *array, int count, t_median *data)
{
	data->min = array[0];
	data->max = array[count - 1];
	data->median = array[count / 2];
}

void	ft_stacks(t_stacks *ps, int *array)
{
	int		i;
	t_list	*tmp;

	i = ps->size;
	while (i--)
	{
		tmp = ft_lstnew(&ps->array[i]);
		if (tmp)
			ft_lstadd_front(&ps->a, tmp);
		else
		{
			free(ps->array);
			while (ps->a != NULL)
			{
				tmp = ps->a;
				ps->a = ps->a->next;
				free(tmp);
			}
			free(array);
			error();
		}
	}
	ps->size_a = ps->size;
}

void	sorter(t_stacks *ps, t_median *data)
{
	if (ps->size == 2)
		sa(ps);
	else if (ps->size < 4)
		ft_three(ps);
	else if (ps->size < 6)
		ft_five(ps);
	else
		sort(ps, data);
}

int	ft_cheaking_for_sortint(t_stacks *ps)
{
	t_list	*tmp;

	tmp = ps->a;
	while (tmp && tmp->next)
	{
		if (*(int *)(tmp->content) > *(int *)(tmp->next->content))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
