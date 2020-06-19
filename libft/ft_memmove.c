/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:43:02 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/29 11:43:19 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*src_cast;
	char			*dst_cast;
	size_t			i;

	i = 0;
	src_cast = (char *)src;
	dst_cast = (char *)dst;
	if (len <= 0)
		return (dst);
	else if (src_cast < dst_cast)
	{
		while (len)
		{
			dst_cast[len - 1] = src_cast[len - 1];
			len--;
		}
		return (dst);
	}
	else
	{
		ft_memcpy(dst_cast, src_cast, len);
		return (dst);
	}
}
