/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:51:20 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 17:06:18 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>

struct dirent	*dp;
struct stat		filestat;
struct passwd	*pass;
struct group	*grpss;

typedef struct	pathlist
{
	char		*name;
	nlink_t		links;
	char		*path;
	char		*user;
	char		*group;
	char		permissions[11];
	off_t		filesize;
	char		*date;
	time_t		mtime;
	int			type;
	mode_t		mode;
	int			blocks;
	struct pathlist	*next;
}				pathlist;

pathlist	*SortedMerge_time(pathlist	*a, pathlist *b, unsigned int flags);
pathlist	*SortedMerge(pathlist *a, pathlist *b, unsigned char flags);
pathlist	*items_lst(struct dirent *dp, char *path);
void		FrontBackSplit(pathlist *source, pathlist **front_ref, pathlist **back_ref);
void		recursive(pathlist *list, char *basepath, unsigned char flags);
void		add_list(pathlist **list, struct dirent *dp, char *path);
void		file_permissions(struct stat filestat, pathlist *node);
void		merge_sort(pathlist **head_ref, unsigned char flags);
void		print_normal(pathlist *list, unsigned char flags);
void		print_output(pathlist *list, unsigned char flags);
void		print_list(pathlist *list, unsigned char flags);
void		blocks(pathlist *ptr, unsigned char flags);
void		ft_ls(char *path, unsigned char flags);
void		reverse_list(pathlist **head);
void		clear_list(pathlist **list);
void		longformat(pathlist *list);
void		permission(char *path);
void		error_file(char *path);
void		illegal_option(char c);
void		hidden(char *path);
int			options_execute(int ac, char **av, unsigned char flags);
int			check(char *path, DIR *dp, int ierrno, unsigned int flag);
int			flags_(char c);
char		*userid(struct stat filestat);
char		*groupid(struct stat filestat);
unsigned char	getflag(unsigned char flags);
unsigned char	option_parser(int ac, char **av);

#endif