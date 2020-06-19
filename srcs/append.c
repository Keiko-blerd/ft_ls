/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:21:58 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 16:47:53 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

pathlist	*items_lst(struct dirent *dp, char *path)
{
    pathlist	*new;
    char		*fullpath;
    char		*path2;
    
    if (!(new =(pathlist *)malloc(sizeof(*new))))
        return (NULL);
    path2 = ft_strjoin(path, "/");
    fullpath = ft_strjoin(path2 , dp->d_name);
    lstat(fullpath, &filestat);
    new->name = ft_strdup(dp->d_name);
    new->links = filestat.st_nlink;
    new->user = userid(filestat);
    new->group = groupid(filestat);
    file_permissions(filestat, new);
    new->type = dp->d_type;
    new->mode = filestat.st_mode;
    new->filesize = filestat.st_size;
    new->date = ft_strsub((ctime(&filestat.st_mtime)), 4, 12);
    new->mtime = filestat.st_mtime;
    new->blocks = filestat.st_blocks;
    new->next = NULL;
    free(path2);
    free(fullpath);
    return (new);
}

void	add_list(pathlist **list, struct dirent *dp, char *path)
{
    pathlist	*new;

    new = items_lst(dp, path);
    new->next = *list;
    *list = new;
}

void	clear_list(pathlist **list)
{
    pathlist	*current;
    pathlist	*next;

	current = *list;
    while (current)
    {
        next = current->next;
        free(current->name);
        free(current->user);
        free(current->group);
        free(current->date);
        free(current);
        current = next;
    }
    *list = NULL;
}

void	reverse_list(pathlist **head)
{
	pathlist	*current;
	pathlist	*previous;
	pathlist	*next;

	next = NULL;
	previous = NULL;
	current = *head;
	while (current != NULL)
	{

		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}