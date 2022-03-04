/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:06:34 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/04 22:06:59 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	error(void)
{
	ft_putstr_fd("error", 2);
	exit(1);
}

void	ft_digit_value(char *s)
{
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t' \
		|| *s == '\v' || *s == '\f' || *s == '\r'))
	{
		s++;
	}
	if (*s && (*s == '+' || *s == '-'))
		s++;
	while (*s)
	{
		if (ft_isdigit(*s) != 1)
			error();
		s++;
	}
}

// int	ft_long_long(char *s)
// {
// 	long long int	i;

// 	if (ft_strlen(s) > 11)
// 		return (1);
// 	i = ft_atoi(s);
// 	if (i > 2147483647 || i < -2147483648)
// 		return (1);
// 	return (0);
// }

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
				error(); //free
		}
	}
}
// int	ft_not_repeat(int argc, char **argv)
// {
// 	int	*array;
// 	int	i;
// 	int	j;

// 	array = malloc(sizeof(int) * (argc - 1));
// 	if (array == NULL)
// 		return (1);
// 	i = -1;
// 	while (++i < argc - 1)
// 		array[i] = ft_atoi(argv[i + 1]);
// 	i = -1;
// 	while (++i < argc - 2)
// 	{
// 		j = i;
// 		while (++j < argc - 1)
// 		{
// 			if (array[i] == array[j])
// 			{
// 				free (array);
// 				return (1);
// 			}
// 		}
// 	}
// 	free (array);
// 	return (0);
// }

// int	checker(char *s)
// {
// 	int	error;

// 	error = 0;
// 	error = ft_digit_value(s);
// 	if (error > 0)
// 		return (error);
// 	error = ft_long_long(s);
// 	if (error > 0)
// 		return (error);
// 	// error = ft_not_repeat(argc, argv);
// 	// if (error > 0)
// 	// 	return (error);
// 	return (0);
// }

// int	*ft_array(int argc, char **argv)
// {
// 	int	*array;
// 	int	i;

// 	array = malloc(sizeof(int) * (argc - 1));
// 	if (array == NULL)
// 		exit (1);
// 	i = -1;
// 	while (++i < argc - 1)
// 		array[i] = ft_atoi(argv[i + 1]);
// 	i = -1;
// 	return (array);
// }

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

int	*ft_sort_full_array(int count, char **argv)
{
	char	**sent_array;
	int		*array;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	array = malloc(count * sizeof(int));
	if (!array)
		error();
	while (argv[i])
	{
		sent_array = ft_split(argv[i], ' ');
		if (!sent_array)
			error();
		i++;
		j = 0;
		while (sent_array[j])
		{
			ft_digit_value((sent_array[j]));
			array[k] = ft_atoi(sent_array[j]);
			k++;
			free(sent_array[j++]);
		}
	}
	free(sent_array);
	return (array);
}

int	*ft_full_array(char **argv)
{
	int		j;
	int		count;
	int		i;
	char	**array;
	int		*sent_array;

	count = 0;
	i = 0;
	j = 1;
	while (argv[j])
	{
		array = ft_split(argv[j], ' ');
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
	sent_array = ft_sort_full_array(count, argv);
	return (sent_array);
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
		if (!array)
			error();
		j++;
		i = 0;
		while (array[i])
		{
			// printf("array: %s\n", array[i]);
			count++;
			free(array[i++]);
		}
		free(array);
	}
	return (count);
}

void	ft_median(int *array, int count, t_median *data)
{
	data->min = array[0];
	data->max = array[count - 1];
	data->median = array[(count - 1) / 2];
}

int	main(int argc, char **argv)
{
	int			*array;
	int			count;
	t_median	data;

	if (argc == 1)
		return (0);
	array = ft_full_array(argv);
	count = ft_count(argv);
	ft_not_repeat(count, array);
	ft_sort_array(array, count + 1);
	ft_median(array, count, &data);
	// array = ft_array(argc, argv);

	
	int	i = 0;
	while (i < count)
	{
		printf("%d\n",array[i]);
		i++;
	}
		
	printf("[%d]\n", data.max);
	printf("[%d]\n", data.min);
	printf("[%d]\n", data.median);
	return (0);
}
