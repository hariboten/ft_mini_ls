/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fml_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:07:01 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 23:14:17 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fml_bonus.h"

int		option_branch(t_fml *fml, char opt)
{
	if (opt == 'G')
		fml->f_put_file_name = put_file_name_with_color;
	else if (opt == 'S')
		fml->f_cmp = cmp_fsize_larger;
	else if (opt == 'u')
		fml->f_cmp = cmp_atime_newer;
	else if (opt == 'U')
		fml->f_cmp = do_not_sort;
	else if (opt == 't')
		fml->f_cmp = cmp_name_less;
	else if (opt == 'r')
		fml->f_output = output_ascending;
	else if (opt == 'a')
		fml->f_ignore_dot = show_all_file;
	else
	{
		ft_putendl_fd("ft_mini_ls: invailed arg", 2);
		return (-1);
	}
	return (0);
}

int		parse_arg(t_fml *fml, int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
		{
			ft_putendl_fd("ft_mini_ls: invailed arg", 2);
			return (-1);
		}
		while (*argv[i])
			if (option_branch(fml, *argv[i]++) < -1)
				return (-1);
	}
	return (0);
}

int		fml_init_with_arg(t_fml *fml, int argc, char **argv)
{
	*fml = (t_fml){0};
	if (!(fml->dir = opendir("./")))
	{
		perror("ft_mini_ls");
		return (-1);
	}
	fml->f_cmp = cmp_mtime_newer;
	fml->f_output = output;
	fml->f_put_file_name = put_file_name;
	fml->f_ignore_dot = ignore_dot;
	if (parse_arg(fml, argc, argv) < 0)
		return (-1);
	return (0);
}
