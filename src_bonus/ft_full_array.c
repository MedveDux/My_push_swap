/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:38:00 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/22 19:40:35 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	initilization(int *i, int **array, int *flag, int *count)
{
	*i = 1;
	*flag = 0;
	*array = malloc(*count * sizeof(int));
	if (!array)
		error();
	*count = 0;
}

void	if_sent(int *i, int *j, char **sent_array, int *array)
{
	if (!sent_array)
		ft_clear(&array);
	(*i)++;
	*j = 0;
}

int	*ft_full_array(int count, char **argv)
{
	char	**sent_array;
	int		*array;
	int		i;
	int		j;
	int		flag;

	initilization(&i, &array, &flag, &count);
	while (argv[i] && !flag)
	{
		sent_array = ft_split(argv[i], ' ');
		if_sent(&i, &j, sent_array, array);
		while (sent_array[j])
		{
			if (!flag)
			{
				if (ft_atoi(sent_array[j], &array[count++]) == -1)
					flag = -1;
			}
			free(sent_array[j++]);
		}
		free(sent_array);
	}
	if (flag == -1)
		ft_clear(&array);
	return (array);
}

void	ft_clear(int **array)
{
	free(*array);
	*array = NULL;
	error();
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
