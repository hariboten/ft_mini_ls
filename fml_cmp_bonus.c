/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fml_cmp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:51:02 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 23:31:10 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fml_bonus.h"

bool	cmp_fsize_larger(int lhs, int rhs, const void *ref)
{
	const t_fml	*fml;

	fml = (const t_fml *)ref;
	if (fml->stat_arr[lhs].st_size != fml->stat_arr[rhs].st_size)
		return (fml->stat_arr[lhs].st_size > fml->stat_arr[rhs].st_size);
	if (ft_strcmp(fml->dirent_arr[lhs]->d_name,
				fml->dirent_arr[rhs]->d_name) < 0)
	{
		return (true);
	}
	return (false);
}

bool	cmp_name_less(int lhs, int rhs, const void *ref)
{
	const t_fml	*fml;

	fml = (const t_fml *)ref;
	if (ft_strcmp(fml->dirent_arr[lhs]->d_name,
				fml->dirent_arr[rhs]->d_name) < 0)
	{
		return (true);
	}
	return (false);
}

bool	cmp_atime_newer(int lhs, int rhs, const void *ref)
{
	const t_fml	*fml;

	fml = (const t_fml *)ref;
	if (fml->stat_arr[lhs].st_atimespec.tv_sec
			!= fml->stat_arr[rhs].st_atimespec.tv_sec)
	{
		return (fml->stat_arr[lhs].st_atimespec.tv_sec
				> fml->stat_arr[rhs].st_atimespec.tv_sec);
	}
	if (fml->stat_arr[lhs].st_atimespec.tv_nsec
			!= fml->stat_arr[rhs].st_atimespec.tv_nsec)
	{
		return (fml->stat_arr[lhs].st_atimespec.tv_nsec
				> fml->stat_arr[rhs].st_atimespec.tv_nsec);
	}
	if (ft_strcmp(fml->dirent_arr[lhs]->d_name,
				fml->dirent_arr[rhs]->d_name) < 0)
	{
		return (true);
	}
	return (false);
}

bool	cmp_ctime_newer(int lhs, int rhs, const void *ref)
{
	const t_fml	*fml;

	fml = (const t_fml *)ref;
	if (fml->stat_arr[lhs].st_ctimespec.tv_sec
			!= fml->stat_arr[rhs].st_ctimespec.tv_sec)
	{
		return (fml->stat_arr[lhs].st_ctimespec.tv_sec
				> fml->stat_arr[rhs].st_ctimespec.tv_sec);
	}
	if (fml->stat_arr[lhs].st_ctimespec.tv_nsec
			!= fml->stat_arr[rhs].st_ctimespec.tv_nsec)
	{
		return (fml->stat_arr[lhs].st_ctimespec.tv_nsec
				> fml->stat_arr[rhs].st_ctimespec.tv_nsec);
	}
	if (ft_strcmp(fml->dirent_arr[lhs]->d_name,
				fml->dirent_arr[rhs]->d_name) < 0)
	{
		return (true);
	}
	return (false);
}
