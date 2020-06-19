/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:40:48 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/29 12:44:36 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*s2== '\0' || s2 == NULL)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j] && i + j < n)
		{
			if (s2[j + 1] == '\0')
			{
				return ((char*)s1 + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}