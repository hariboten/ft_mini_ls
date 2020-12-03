/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fml_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:07:01 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 22:40:26 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fml_bonus.h"

void	change_color(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putstr("\x1b[34m\x1b[49m");
	if (S_ISLNK(mode))
		ft_putstr("\x1b[35m\x1b[49m");
	if (mode & S_IFSOCK)
		ft_putstr("\x1b[32m\x1b[49m");
	if (S_ISFIFO(mode))
		ft_putstr("\x1b[33m\x1b[49m");
	if (!S_ISDIR(mode) && mode & S_IXUSR)
		ft_putstr("\x1b[31m\x1b[49m");
	if (S_ISBLK(mode))
		ft_putstr("\x1b[34m\x1b[46m");
	if (S_ISCHR(mode))
		ft_putstr("\x1b[34m\x1b[43m");
	if (!S_ISDIR(mode) && mode & S_ISUID)
		ft_putstr("\x1b[30m\x1b[41m");
	if (!S_ISDIR(mode) && mode & S_ISGID)
		ft_putstr("\x1b[30m\x1b[46m");
	if (S_ISDIR(mode) && mode & S_IXOTH && mode & S_ISVTX)
		ft_putstr("\x1b[30m\x1b[42m");
	if (S_ISDIR(mode) && mode & S_IXOTH && !(mode & S_ISVTX))
		ft_putstr("\x1b[30m\x1b[43m");
}

void	put_file_name_with_color(const t_dirent *file)
{
	t_stat	sb;

	if (stat(file->d_name, &sb) < 0)
		return ;
	change_color(sb.st_mode);
	ft_putstr_fd((char *)file->d_name, 1);
	ft_putendl_fd("\x1b[39m\x1b[49m", 1);
}

int		option_branch(t_fml *fml, char opt)
{
	if (opt == 'G')
		fml->f_put_file_name = put_file_name_with_color;
	else
	{
		ft_putendl_fd("ft_mini_ls: invailed arg", 2);
		return (-1);
	}
	return (0);
}

int		parse_arg(t_fml *fml, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
		{
			ft_putendl_fd("ft_mini_ls: invailed arg", 2);
			return (-1);
		}
		while (*argv[i])
			if (option_branch(fml, *argv[i]++) < -1)
				return (-1);
	}
	return (0);
}

int		fml_init_with_arg(t_fml *fml, int argc, char **argv)
{
	*fml = (t_fml){0};
	if (!(fml->dir = opendir("./")))
	{
		perror("ft_mini_ls");
		return (-1);
	}
	fml->f_cmp = cmp_mtime_newer;
	fml->f_output = output;
	fml->f_put_file_name = put_file_name;
	fml->f_ignore_dot = ignore_dot;
	if (parse_arg(fml, argc, argv) < 0)
		return (-1);
	return (0);
}
