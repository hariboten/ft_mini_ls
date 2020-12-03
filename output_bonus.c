/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:13:25 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/04 00:01:32 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fml_bonus.h"


void	change_color(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putstr("\x1b[34m\x1b[49m");
	if (S_ISLNK(mode))
		ft_putstr("\x1b[35m\x1b[49m");
	if (mode & S_IFSOCK && false)
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
	if (S_ISDIR(mode) && mode & S_IWOTH && mode & S_ISVTX)
		ft_putstr("\x1b[30m\x1b[42m");
	if (S_ISDIR(mode) && mode & S_IWOTH && !(mode & S_ISVTX))
		ft_putstr("\x1b[30m\x1b[43m");
}

void	put_file_name_with_color(const t_dirent *file)
{
	t_stat	sb;

	if (lstat(file->d_name, &sb) < 0)
		return ;
	change_color(sb.st_mode);
	ft_putstr_fd((char *)file->d_name, 1);
	ft_putendl_fd("\x1b[39m\x1b[49m", 1);
}

bool	show_all_file(const t_dirent *file)
{
	(void)file;
	return (true);
}

void	output_ascending(t_fml *fml)
{
	int		i;

	i = 0;
	while (i < fml->num_ent)
	{
		if (fml->f_ignore_dot(fml->dirent_arr[fml->index[i]]))
			fml->f_put_file_name(fml->dirent_arr[fml->index[i]]);
		i++;
	}
}
