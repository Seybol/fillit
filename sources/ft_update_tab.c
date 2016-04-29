/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:52:47 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 19:47:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_update_tab(char **tab, int x, int y, t_tetri *t)
{
	int i;

	i = -1;
	while (++i < 4)
		tab[y + t->y[i]][x + t->x[i]] = t->letter;
}

void	ft_repare_tab(char **tab, int x, int y, t_tetri *t)
{
	int i;

	i = -1;
	while (++i < 4)
		tab[y + t->y[i]][x + t->x[i]] = '.';
}
