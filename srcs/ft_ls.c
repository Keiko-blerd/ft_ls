/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:02:37 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 17:03:36 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_ls(char *path, unsigned char flags)
{
	pathlist	*initial;
	DIR			*dir;

	initial = NULL;
	dp = NULL;
	dir = opendir(path);
	if (check(path, dir, errno, flags) == 1)
		return ;
	while ((dp = readdir(dir)))
	{
		if (!initial)
			initial = items_lst(dp, path);
		else
			add_list(&initial, dp, path);
	}
	closedir(dir);
	if (!(flags & 16))
		merge_sort(&initial, flags);
	else
		reverse_list(&initial);
	print_output(initial, flags);
	recursive(initial, path, flags);
	clear_list(&initial);
}

int		main(int ac, char **av)
{
	unsigned char	flags;
	int				check;

	check = 0;
	flags = option_parser(ac, av);
	if (ac == 1)
		ft_ls(".", flags);
	else
	{
		check = options_execute(ac, av, flags);
		if (check == 0)
			ft_ls(".", flags);
	}
	return (0);
}