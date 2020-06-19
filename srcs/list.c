/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:20:34 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 16:26:59 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	blocks(pathlist *ptr, unsigned char flags)
{
	int i;

	i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		if ((ptr->name[0] == '.' && flags & 2) || ptr->name[0] != '.')
			i += ptr->blocks;
		ptr = ptr->next;
	}
	ft_putnbr(i);
	ft_putchar('\n');
}

char	*userid(struct stat filestat)
{
    pass = getpwuid(filestat.st_uid);
    if (pass == NULL)
    	perror("getpwuid");
    else
        return(ft_strdup(pass->pw_name));
    return (NULL);   
}

char	*groupid(struct stat filestat)
{  
    grpss = getgrgid(filestat.st_gid);
    if (grpss == NULL)
    	perror("getgid");
    else
		return (ft_strdup(grpss->gr_name));
	return (NULL);
}

void	file_permissions(struct stat filestat, pathlist *node)
{
            node->permissions[0] = (S_ISDIR(filestat.st_mode) ? 'd' : '-');
            node->permissions[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
			node->permissions[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
			node->permissions[3] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
			node->permissions[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
			node->permissions[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
			node->permissions[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
			node->permissions[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
			node->permissions[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
			node->permissions[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
            node->permissions[10] = '\0';
}