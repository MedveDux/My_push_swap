/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:38:41 by cyelena           #+#    #+#             */
/*   Updated: 2022/03/18 18:43:08 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *number)
{
	unsigned long	res;
	int				negative;

	negative = 1;
	res = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		++str;
	}
	if (!*str)
		return (-1);
	while (*str && *str >= '0' && *str <= '9')
	{
		if ((res > (unsigned int)(-1) / 2 && negative == 1)
			|| (res > ((unsigned int)(-1) / 2 + 1) && negative == -1))
			return (-1);
		res = res * 10 + (*str - '0');
		++str;
	}
	if (*str)
		return (-1);
	*number = ((int)res) * negative;
	return (0);
}
