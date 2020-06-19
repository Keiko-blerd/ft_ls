/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:27:00 by nhlatshw          #+#    #+#             */
/*   Updated: 2019/06/18 11:36:32 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s1_dup;
	unsigned long	i;

	i = 0;
	s1_dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s1_dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1_dup[i] = s1[i];
		i++;
	}
	if (s1_dup == NULL)
	{
		return (NULL);
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
