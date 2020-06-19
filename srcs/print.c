/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:16:18 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 17:07:26 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	longformat(pathlist *list)
{
	if ((S_ISLNK(list->mode)))
		ft_putstr("l");
	else
		ft_putstr(list->permissions);
	ft_putchar(' ');
	ft_putnbr(list->links);
	ft_putchar('\t');
	ft_putstr(list->user);
	ft_putchar(' ');
	ft_putstr(list->group);
	ft_putchar(' ');
	ft_putnbr(list->filesize);
	ft_putchar('\t');
	ft_putstr(list->date);
	ft_putchar(' ');
	ft_putendl(list->name);
}

void	print_list(pathlist *list, unsigned char flags)
{
	pathlist	*ptr;
	pathlist	*ptr2;

	ptr = list;
	ptr2 = list;
	if (flags & 1)
		blocks(ptr2, flags);
	while (ptr != NULL)
	{
		if (flags & 2)
			longformat(ptr);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			longformat(ptr);
		ptr = ptr->next;
	}
}

void	print_normal(pathlist *list, unsigned char flags)
{
	pathlist	*ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
			ft_putendl(ptr->name);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			ft_putendl(ptr->name);
		ptr = ptr->next;
	}
}

void	print_output(pathlist *list, unsigned char flags)
{
	if (flags & 1)
		print_list(list, flags);
	else
		print_normal(list, flags);
}