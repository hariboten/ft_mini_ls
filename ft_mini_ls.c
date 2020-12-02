/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:15:05 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/02 14:48:49 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	put_file_name(const t_dirent *file)
{
	ft_putendl_fd((char *)file->d_name, 1);
}

void	**ft_lsttov(t_list	*lst)
{
	int		size;
	void	**v;
	int		i;

	size = ft_lstsize(lst);
	if (!(v = ft_calloc(size + 1, sizeof(void *))))
		return (NULL);
	i = 0;
	while (lst)
	{
		v[i++] = lst->content;
		lst = lst->next;
	}
	v[i] = NULL;
	return (v);
}


void	do_nothing(void *ptr)
{
	(void)ptr;
}

int		get_dir_ent(t_fml *fml, DIR *dir)
{
	t_list		*dirent_lst;
	t_dirent	*tmp;
	int			ret;

	dirent_lst = NULL;
	while ((tmp = readdir(dir)))
		ft_lstadd_back(&dirent_lst, ft_lstnew(tmp));
	fml->num_ent = ft_lstsize(dirent_lst);
	ret = 0;
	if (!(fml->dirent_arr = (t_dirent **)ft_lsttov(dirent_lst)))
		ret = -1;
	ft_lstclear(&dirent_lst, do_nothing);
	return (ret);
}

int		get_dir_stat(t_fml *fml)
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

void	ft_mini_ls()
{
	t_fml	fml;
	DIR		*dir;

	fml = (t_fml){0};
	dir = opendir("./");
	get_dir_ent(&fml, dir);
	get_dir_stat(&fml);

	for (int i = 0; i < fml.num_ent; i++)
		put_file_name(fml.dirent_arr[i]);
}
