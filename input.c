/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:11:46 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 14:34:40 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	do_nothing(void *ptr)
{
	(void)ptr;
}

int		input_ents(t_fml *fml)
{
	t_list		*dirent_lst;
	t_dirent	*tmp;
	int			ret;

	dirent_lst = NULL;
	while ((tmp = readdir(fml->dir)))
		ft_lstadd_back(&dirent_lst, ft_lstnew(tmp));
	fml->num_ent = ft_lstsize(dirent_lst);
	ret = 0;
	if (!(fml->dirent_arr = (t_dirent **)ft_lsttov(dirent_lst)))
		ret = -1;
	ft_lstclear(&dirent_lst, do_nothing);
	return (ret);
}

int		get_dir_stats(t_fml *fml)
{
	int		i;
	t_stat	tmp;

	if (!(fml->stat_arr = ft_calloc(fml->num_ent, sizeof(t_stat))))
		return (-1);
	i = 0;
	while (i < fml->num_ent)
	{
		if (stat(fml->dirent_arr[i]->d_name, &tmp))
			return (-1);
		fml->stat_arr[i++] = tmp;
	}
	return (0);
}

int		input(t_fml *fml)
{
	if (input_ents(fml) < 0)
	{
		perror("ft_mini_ls");
		return (-1);
	}
	if (get_dir_stats(fml) < 0)
	{
		perror("ft_mini_ls");
		return (-1);
	}
	return (0);
}
