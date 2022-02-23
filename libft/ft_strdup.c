/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:22:32 by cyelena           #+#    #+#             */
/*   Updated: 2022/02/04 20:22:35 by cyelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;

	s1 = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!s1)
		return (NULL);
	ft_strlcpy(s1, s, ft_strlen(s) + 1);
	return (s1);
}
