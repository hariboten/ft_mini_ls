/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:17:04 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/04 00:26:28 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fml_bonus.h"

int		main(int argc, char **argv)
{
	t_fml	fml;
	int		exit_state;

	if (argc != 1)
	{
		if (fml_init_with_arg(&fml, argc, argv) < 0)
			return (-1);
	}
	else if (fml_init(&fml) < 0)
		return (-1);
	exit_state = ft_mini_ls(&fml);
	if (fml_destroy(&fml) < 0)
		return (-1);
	return (exit_state);
}
