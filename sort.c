/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:14:45 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 19:15:36 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		*ft_range(int begin, int end)
{
	int		i;
	int		*range;

	if (begin >= end)
		return (NULL);
	if (!(range = ft_calloc(end - begin, sizeof(int))))
		return (NULL);
	i = 0;
	while (begin + i < end)
	{
		range[i] = begin + i;
		i++;
	}
	return (range);
}

bool	cmp_mtime_newer(int lhs, int rhs, const void *ref)
{
	const t_fml	*fml;

	fml = (const t_fml *)ref;
	if (fml->stat_arr[lhs].st_mtimespec.tv_sec
			!= fml->stat_arr[rhs].st_mtimespec.tv_sec)
	{
		return (fml->stat_arr[lhs].st_mtimespec.tv_sec
				< fml->stat_arr[rhs].st_mtimespec.tv_sec);
	}
	if (fml->stat_arr[lhs].st_mtimespec.tv_nsec
			!= fml->stat_arr[rhs].st_mtimespec.tv_nsec)
	{
		return (fml->stat_arr[lhs].st_mtimespec.tv_nsec
				< fml->stat_arr[rhs].st_mtimespec.tv_nsec);
	}
	if (ft_strcmp(fml->dirent_arr[lhs]->d_name,
				fml->dirent_arr[rhs]->d_name) < 0)
	{
		return (true);
	}
	return (false);
}

int		*index_sort(bool cmp(int, int, const void *), const void *ref, int size)
{
	int		*index;
	int		min;
	int		i;
	int		j;

	if (!(index = ft_range(0, size)))
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (cmp(index[j], index[min], ref))
				min = j;
			j++;
		}
		ft_swap(&index[i], &index[min]);
		i++;
	}
	return (index);
}

int		sort(t_fml *fml)
{
	if (!(fml->index = index_sort(cmp_mtime_newer, fml, fml->num_ent)))
	{
		perror("ft_mini_ls");
		return (-1);
	}
	return (0);
}
