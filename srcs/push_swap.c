/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:06:34 by cyelena           #+#    #+#             */
/*   Updated: 2022/02/23 17:34:10 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// char	*ft_line(int argc, char **argv)
// {
// 	char	*line_array;
// 	int		i;

// 	i = 2;
// 	printf ("argc %d\n", argc);
// 	printf ("argv %s\n", argv[1]);
// 	line_array = argv[1];
// 	while (i < argc)
// 	{
// 		line_array = ft_strjoin(ft_strjoin(line_array, " "), argv[i]);
// 		i++;
// 	}
// 	return (line_array);
// }

int	ft_digit_value(char *argv)
{
	while (*argv && (*argv == ' ' || *argv == '\n' || *argv == '\t' \
		|| *argv == '\v' || *argv == '\f' || *argv == '\r'))
	{
		argv++;
	}
	if (*argv && (*argv == '+' || *argv == '-'))
		argv++;
	while (*argv)
	{
		if (ft_isdigit(*argv) != 1)
			return (1);
		argv++;
	}
	return (0);
}

int	ft_long_long(char *argv)
{
	long long int	i;

	if (ft_strlen(argv) > 11)
		return (1);
	i = ft_atoi(argv);
	if (i > 2147483647 || i < -2147483648)
		return (1);
	return (0);
}

int	ft_not_repeat(int argc, char **argv)
{
	int	*array;
	int	i;
	int	j;

	array = malloc(sizeof(int) * (argc - 1));
	if (array == NULL)
		return (1);
	i = -1;
	while (++i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
	}
	i = -1;
	while (++i < argc - 2)
	{
		j = i;
		while (++j < argc - 1)
			if (array[i] == array[j])
				return (1);
	}
	free (array);
	return (0);
}

int	checker(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (i < argc)
	{
		error = ft_digit_value(argv[i]);
		if (error > 0)
			return (error);
		error = ft_long_long(argv[i]);
		if (error > 0)
			return (error);
		i++;
	}
	error = ft_not_repeat(argc, argv);
	if (error > 0)
		return (error);
	return (0);
}

int	main(int argc, char **argv)
{
	if (checker(argc, argv) > 0)
	{
		ft_putstr_fd("error", 2);
	}
	// char	*line_array;
	// char	**array;

	// line_array = ft_line(argc, argv);
	// array = ft_split(line_array, " ");
	return (0);
}
