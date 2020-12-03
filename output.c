/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:15:51 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 21:18:15 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

bool	ignore_dot(const t_dirent *file)
{
	if (!file)
		return (false);
	if (file->d_name[0] == '.')
		return (false);
	return (true);
}

void	put_file_name(const t_dirent *file)
{
	ft_putendl_fd((char *)file->d_name, 1);
}

void	output(t_fml *fml)
{
	int		i;

	i = fml->num_ent;
	while (--i >= 0)
		if (fml->f_ignore_dot(fml->dirent_arr[fml->index[i]]))
			fml->f_put_file_name(fml->dirent_arr[fml->index[i]]);
}
