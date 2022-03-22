/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cheaker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:41:32 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/22 20:55:49 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_not_repeat(int k, int *array)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < k - 1)
	{
		j = i;
		while (++j < k)
		{
			if (array[i] == array[j])
				ft_clear(&array);
		}
	}
}

void	ft_sort_array(int *array, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (++j < argc - i - 2)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int	ft_count(char **argv)
{
	int		j;
	int		count;
	int		i;
	char	**array;

	count = 0;
	i = 0;
	j = 1;
	while (argv[j])
	{
		array = ft_split(argv[j], ' ');
		if (!ft_strncmp("", argv[1], 1))
			error();
		if (!array)
			error();
		j++;
		i = 0;
		while (array[i])
		{
			count++;
			free(array[i++]);
		}
		free(array);
	}
	return (count);
}
