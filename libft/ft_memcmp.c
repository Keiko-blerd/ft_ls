/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:23:28 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/06 11:48:56 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	const char		*s1_cast;
	const char		*s2_cast;

	i = 0;
	s1_cast = (const char *)s1;
	s2_cast = (const char *)s2;
	while (i < n)
	{
		if (s1_cast[i] != s2_cast[i])
			return ((unsigned char)s1_cast[i] - (unsigned char)s2_cast[i]);
		i++;
	}
	return (0);
}
