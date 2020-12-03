/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:43:03 by ewatanab          #+#    #+#             */
/*   Updated: 2020/12/03 14:32:03 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttov(t_list *lst)
{
	void	**vec;
	void	**ret;

	if (!(vec = ft_calloc(ft_lstsize(lst) + 1, sizeof(void *))))
		return (NULL);
	ret = vec;
	while (lst)
	{
		*vec++ = lst->content;
		lst = lst->next;
	}
	*vec = NULL;
	return (ret);
}

void	ft_lstvclear(void **lst)
{
	void	**tmp;

	tmp = lst;
	while (*lst)
		free(*lst++);
	free(tmp);
}
