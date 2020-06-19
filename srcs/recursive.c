/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:09:31 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 16:13:37 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	recursive(pathlist *list, char *basepath, unsigned char flags)
{
	pathlist	*node;
	char		*s1;
	char		*s2;

	node = list;
	if (flags & 4)
		while (node != NULL)
	{
		if ((node->type == 4) && (ft_strcmp(node->name, ".") != 0) &&
		 (ft_strcmp(node->name, "..") != 0))
		{
			if (!(flags & 2) && (node->name[0] == '.'))
			{
				node = node->next;
				continue ;
			}
			s1 = ft_strjoin("/", node->name);
			s2 = ft_strjoin(basepath, s1);
			free(s1);
			ft_ls(s2, flags);
			free(s2);
		}
		node = node->next;
	}
}