/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fml_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:08:06 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 22:06:46 by ewatanab         ###   ########.fr       */
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

#endif
