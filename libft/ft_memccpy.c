/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:20:09 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/13 16:01:13 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long	i;
	char			*dst_cast;
	char			*src_cast;

	i = 0;
	dst_cast = (char *)dst;
	src_cast = (char *)src;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		if ((unsigned char)src_cast[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
