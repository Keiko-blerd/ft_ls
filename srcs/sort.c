/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:24:04 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 16:16:39 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	merge_sort(pathlist **head_ref, unsigned char flags)
{
	pathlist	*head;
	pathlist	*a;
	pathlist	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	FrontBackSplit(head, &a, &b);
	merge_sort(&a, flags);
	merge_sort(&b, flags);
	if (flags & 16)
		*head_ref = SortedMerge_time(a, b, flags);
	else
		*head_ref = SortedMerge(a, b, flags);
}

pathlist	*SortedMerge(pathlist *a, pathlist *b, unsigned char flags)
{
	pathlist	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 8) && ((ft_strcmp(a->name, b->name)) < 0))
	{
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else if ((flags & 8) && ((ft_strcmp(a->name, b->name)) > 0))
	{
		result = a;
		result->next = SortedMerge(a->next, b, flags);
	}
	else 
	{
		result = b;
		result->next = SortedMerge(a, b->next, flags);
	}
	return (result);
}

pathlist	*SortedMerge_time(pathlist	*a, pathlist *b, unsigned int flags)
{
	pathlist	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (!(flags & 16) && (a->mtime > b->mtime))
	{
		result = a;
		result->next = SortedMerge_time(a->next, b, flags);
	}
	else if ((flags & 16) && (a->mtime < b->mtime))
	{
		result = a;
		result->next = SortedMerge_time(a->next, b, flags);
	}
	else
	{
		result = b;
		result->next = SortedMerge_time(a, b->next, flags);
	}
	return (result);
}


void	FrontBackSplit(pathlist *source, pathlist **front_ref, pathlist **back_ref)
{
	pathlist	*fast;
	pathlist	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}
