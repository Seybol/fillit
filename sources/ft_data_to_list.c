/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:43:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/16 17:23:59 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_pushback(t_list **alst, void *c, size_t c_size)
{
	t_list	*list;

	list = *alst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(c, c_size);
	}
	else
		*alst = ft_lstnew(c, c_size);
}

int			ft_data_to_list(t_list **begin_list, int fd)
{
	int		ret;
	int		n;
	char	buf[22];

	n = 0;
	ret = 0;
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		ft_lst_pushback(begin_list, buf, 22);
		++n;
		if (n > 26)
			break ;
	}
	if (n > 26)
		return (0);
	if (n == 0 && ret == 0)
		ft_lst_pushback(begin_list, buf, 22);
	return (1);
}

void		ft_initnull(int *fd, t_list **l, t_tetri **t, t_data **d)
{
	*fd = 0;
	*l = NULL;
	*t = NULL;
	*d = NULL;
}
