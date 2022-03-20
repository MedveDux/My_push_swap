/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:06:34 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/20 19:50:56 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void ft_clear(int **array)
{
	free(*array);
	*array = NULL;
	error();
}
void error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

// int	ft_digit_value(char *s)
// {
// 	while (*s && (*s == ' ' || *s == '\n' || *s == '\t' \
// 		|| *s == '\v' || *s == '\f' || *s == '\r'))
// 	{
// 		s++;
// 	}
// 	if (*s && (*s == '+' || *s == '-'))
// 		s++;
// 	while (*s)
// 	{
// 		if (ft_isdigit(*s) != 1)
// 			return (-1);
// 		s++;
// 	}
// 	return (0);
// }

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

void ft_not_repeat(int k, int *array)
{
	int i;
	int j;

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

void ft_sort_array(int *array, int argc)
{
	int i;
	int j;
	int temp;

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

/*
 *	Malloc array
 *	Checking the array for digit and atoi(not repeat)
 */
int *ft_full_array(int count, char **argv)
{
	char **sent_array;
	int *array;
	int i;
	int j;
	int flag;

	i = 1;
	flag = 0;
	array = malloc(count * sizeof(int));
	if (!array)
		error();
	count = 0;
	while (argv[i] && !flag)
	{
		sent_array = ft_split(argv[i], ' ');
		if (!sent_array)
			ft_clear(&array);
		i++;
		j = 0;
		while (sent_array[j])
		{
			if (!flag)
			{
				if (ft_atoi(sent_array[j], &array[count]) == -1)
					flag = -1;
				count++;
			}
			free(sent_array[j++]);
		}
		free(sent_array);
	}
	if (flag == -1)
		ft_clear(&array);
	return (array);
}
/*
 * The count that will be used ta malloc array
 */
// int	*ft_full_array(char **argv)
// {
// 	int		j;
// 	int		count;
// 	int		i;
// 	char	**array;
// 	int		*sent_array;

// 	count = 0;
// 	i = 0;
// 	j = 1;
// 	while (argv[j])
// 	{
// 		array = ft_split(argv[j], ' ');
// 		if (!array)
// 			error();
// 		j++;
// 		i = 0;
// 		while (array[i])
// 		{
// 			count++;
// 			free(array[i++]);
// 		}
// 		free(array);
// 	}
// 	sent_array = ft_sort_full_array(count, argv);
// 	return (sent_array);
// }

int ft_count(char **argv)
{
	int j;
	int count;
	int i;
	char **array;

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
	return (count);
}
/*
 *	Filling in the structure taking into account the array
 */
void ft_median(int *array, int count, t_median *data)
{
	data->min = array[0];
	data->max = array[count - 1];
	data->median = array[count / 2];
}

// void stacks_init(t_stacks *ps)
// {
// 	t_list	*a;

// 	ps->a = NULL;
// 	ps->b = NULL;
// 	ps->size = 0;
// }

/*
 *	Creating lst
 */
void ft_stacks(t_stacks *ps, int *array)
{
	int i;
	t_list *tmp;

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

void sorter(t_stacks *ps, t_median *data)
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
	t_list *tmp;

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
// int	cheakig_for_sorting(int *array, int size)
// {
// 	int	i;

// 	i = 0;
// 	size--;
// 	while (size)
// 	{
// 		if (array[i] > array[i + 1])
// 			return (1);
// 		i++;
// 		size--;	
// 	}
// 	return (0);
	
// }

int main(int argc, char **argv)
{
	t_median data;
	t_stacks ps;
	int *array;
	int k;

	if (argc == 1)
		return (0);
	ft_memset(&ps, 0, sizeof(ps));
	ps.size = ft_count(argv);
	ps.array = ft_full_array(ps.size, argv);
	ft_not_repeat(ps.size, ps.array);
	array = malloc(sizeof(int) * ps.size);
	k = -1;
	while (++k < ps.size)
		array[k] = (ps.array)[k];
	ft_stacks(&ps, array);
	// if (cheakig_for_sorting(array, ps.size) == 1)
	// {
	// 	free(ps.array);
	// 	ps.array = NULL;
	// 	free(array);
	// 	array = NULL;
	// 	ps.a = NULL;
	// 	return (0);
	// }
	ft_sort_array(array, ps.size + 1);
	ft_median(array, ps.size, &data);
	if (ft_cheaking_for_sortint(&ps) == 0)
	{
		free(ps.array);
		ps.array = NULL;
		free(array);
		array = NULL;
		ft_lstclear(&ps.a);
		ft_lstclear(&ps.b);
		// ps.a = NULL;
		return (0);
	}
	sorter(&ps, &data);
	free(ps.array);
	ps.array = NULL;
	free(array);

	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);

	// int	i = 0;
	// while (i < ps.size)
	// {
	// 	printf("content %d\n", *(int *)ps.a->content);
	// 	ps.a = ps.a->next;
	// 	i++;
	// }
	// i = 0;
	// while (i < ps.size)
	// {
	// 	printf("array %d\n", array[i]);
	// 	i++;
	// }
	// printf("[%d]\n", data.max);
	// printf("[%d]\n", data.min);
	// printf("[%d]\n", data.median);
	return (0);
}
