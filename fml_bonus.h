/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fml_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:08:06 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 23:31:50 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FML_BONUS_H
# define FML_BONUS_H

# include "ft_mini_ls.h"

# ifndef S_IFSOCK
#  define S_IFSOCK 0140000
# endif
# ifndef S_ISVTX
#  define S_ISVTX 0001000
# endif

int		fml_init_with_arg(t_fml *fml, int argc, char **argv);

void	put_file_name_with_color(const t_dirent *file);
void	output_ascending(t_fml *fml);
bool	show_all_file(const t_dirent *file);

bool	cmp_fsize_larger(int lhs, int rhs, const void *ref);
bool	cmp_atime_newer(int lhs, int rhs, const void *ref);
bool	cmp_ctime_newer(int lhs, int rhs, const void *ref);
bool	cmp_name_less(int lhs, int rhs, const void *ref);

#endif
