/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:16:42 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 14:10:39 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		main(int argc, char **argv)
{
	t_fml	fml;
	int		exit_state;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("ft_mini_ls: invailed arg", 2);
		return (-1);
	}
	if (fml_init(&fml) < 0)
		return (-1);
	exit_state = ft_mini_ls(&fml);
	if (fml_destroy(&fml) < 0)
		return (-1);
	return (exit_state);
}
