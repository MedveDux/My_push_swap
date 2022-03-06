/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:38:41 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/06 16:57:17 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error(void)
{
	ft_putstr_fd("error", 2);
	exit(1);
}

static long int	ft_maxmin(long int k)
{
	if (k > INT_MAX)
		error();
	if (k < INT_MIN)
		error();
	return (k);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			negative;

	negative = 1;
	res = 0;
	if ((*str == '-' || *str == '+') && *(str + 1) == '\0')
		error();
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
		*str == '\v' || *str == '\f' || *str == '\r'))
	++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (ft_maxmin(res * negative));
}
