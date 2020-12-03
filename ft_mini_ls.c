/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:15:05 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 14:16:34 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		fml_init(t_fml *fml)
{
	*fml = (t_fml){0};
	if (!(fml->dir = opendir("./")))
	{
		perror("ft_mini_ls");
		return (-1);
	}
	return (0);
}

int		fml_destroy(t_fml *fml)
{
	free(fml->stat_arr);
	free(fml->dirent_arr);
	free(fml->index);
	if (closedir(fml->dir) < 0)
	{
		perror("ft_mini_ls");
		return (-1);
	}
	return (0);
}

int		ft_mini_ls(t_fml *fml)
{
	input(fml);
	if (sort(fml) < 0)
		return (-1);
	output(fml);
	return (0);
}
