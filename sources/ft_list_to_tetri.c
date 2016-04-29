/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:47:35 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 20:47:47 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_find_minxy(size_t *minx, size_t *miny, t_tetri *new)
{
	size_t	j;

	j = 0;
	*minx = new->x[j];
	*miny = new->y[j];
	while (j < 4)
	{
		if ((size_t)new->x[j] < *minx)
			*minx = (size_t)new->x[j];
		if ((size_t)new->y[j] < *miny)
			*miny = (size_t)new->y[j];
		++j;
	}
}

static void		ft_set_xy(size_t *minx, size_t *miny, t_tetri *new)
{
	int		j;

	j = -1;
	while (++j < 4)
	{
		new->x[j] -= *minx;
		new->y[j] -= *miny;
	}
	new->length = ft_max(new->x) + 1;
	new->height = ft_max(new->y) + 1;
}

static t_tetri	*ft_convert_list(char *str, size_t letter)
{
	size_t	minx;
	size_t	miny;
	t_tetri	*new;
	int		i;
	size_t	j;

	j = 0;
	i = -1;
	minx = 0;
	miny = 0;
	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '#')
		{
			new->x[j] = i % 5;
			new->y[j++] = i / 5;
		}
	}
	ft_find_minxy(&minx, &miny, new);
	ft_set_xy(&minx, &miny, new);
	new->letter = letter;
	new->next = NULL;
	return (new);
}

static void		ft_tet_pushback(t_tetri **atet, char *str, size_t letter)
{
	t_tetri *tetri;

	tetri = *atet;
	if (tetri)
	{
		while (tetri->next)
			tetri = tetri->next;
		tetri->next = ft_convert_list(str, letter);
	}
	else
		*atet = ft_convert_list(str, letter);
}

void			ft_create_t_tetri(t_list **list, t_tetri **t, char letter)
{
	while (*list)
	{
		ft_tet_pushback(t, (*list)->content, letter);
		(*list) = (*list)->next;
		++letter;
	}
}
