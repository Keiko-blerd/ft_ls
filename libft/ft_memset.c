/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:04:04 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/29 11:14:58 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cast;

	b_cast = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (len > 0)
	{
		b_cast[len - 1] = c;
		len--;
	}
	return (b);
}
