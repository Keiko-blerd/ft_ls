/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhlatshw <nhlatshw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:13:24 by nhlatshw          #+#    #+#             */
/*   Updated: 2020/06/19 17:06:57 by nhlatshw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		flags_(char c)
{
	if (c == 'l')
		return (1 << 0);
	else if (c == 'a')
		return (1 << 1);
	else if (c == 'R')
		return (1 << 2);
	else if (c == 'r')
		return (1 << 3);
	else if (c == 't')
		return (1 << 4);
	return (0);
}

unsigned char	getflag(unsigned char flags)
{
	error_file("-");
	return (flags);
}

void	illegal_option(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}

int		check_if(char c)
{
	if (flags_(c) != 0)
		return (1);
	else
		return (0);
}

unsigned char	option_parser(int ac, char **av)
{
	int				i;
	int				j;
	unsigned char	flags;

	i = 1;
	flags = '\0';
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			j++;
			if(av[i][1] == '\0')
				return (getflag(flags));
			while (check_if(av[i][j]) == 1)
				flags |= flags_(av[i][j++]);
			if (flags_(av[i][j]) == 0 && av[i][j] != '\0')
				illegal_option(av[i][j]);
		}
		else
			return (flags);
		i++;
	}
	return(flags);
}

int		options_execute(int ac, char **av, unsigned char flags)
{
	int		i;
	int		check;

	i = 1;
	check = 0;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			ft_ls(av[i], flags);
			check = 1;
		}
		i++;
	}
	return (check);
}