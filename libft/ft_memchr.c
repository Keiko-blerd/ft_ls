/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:49:03 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/28 16:01:33 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cast;
	size_t	i;

	s_cast = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s_cast[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
