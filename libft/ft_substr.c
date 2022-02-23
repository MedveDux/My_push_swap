/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:21:11 by cyelena           #+#    #+#             */
/*   Updated: 2022/02/04 20:21:15 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*my_s;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	i = 0;
	my_s = malloc(len + 1);
	if (!my_s)
		return (0);
	while (i < len)
	{
		my_s[i++] = s[start++];
	}
	my_s[i] = '\0';
	return (my_s);
}
