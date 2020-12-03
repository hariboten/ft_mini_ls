/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:09:11 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 14:36:32 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

typedef struct			s_fml
{
	DIR			*dir;
	t_stat		*stat_arr;
	t_dirent	**dirent_arr;
	int			*index;
	int			num_ent;
}						t_fml;

int						ft_mini_ls(t_fml *fml);
int						fml_init(t_fml *fml);
int						fml_destroy(t_fml *fml);
int						input(t_fml *fml);
int						sort(t_fml *fml);
void					output(t_fml *fml);

#endif
