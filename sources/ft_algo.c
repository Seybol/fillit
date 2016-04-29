/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 22:03:06 by scebula           #+#    #+#             */
/*   Updated: 2016/01/18 19:38:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_positions(char **tab, t_tetri *t, int i, int j)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		if (tab[j + t->y[k]][i + t->x[k]] != '.')
			break ;
	}
	return (k);
}

int			ft_algo(int p, t_tetri *t, char **tab, t_data *d)
{
	int x;
	int y;

	if (p == -1)
		return (0);
	ft_coor_init(&x, &y, p, d);
	if (t->next)
	{
		ft_update_tab(tab, x, y, t);
		if (!ft_algo(ft_next_position(0, tab, d, t->next), t->next, tab, d))
		{
			ft_repare_tab(tab, x, y, t);
			return (ft_algo(ft_next_position(p + 1, tab, d, t), t, tab, d));
		}
		return (1);
	}
	else
	{
		ft_update_tab(tab, x, y, t);
		d->max_found = ft_tab_max_square(tab);
		d->tabmax = (d->max_found < d->max) ? ft_copytab(tab) : d->tabmax;
		d->max = (d->max_found < d->max) ? d->max_found : d->max;
	}
	return (ft_algo(ft_next_position(p + 1, tab, d, t), t, tab, d));
}

int			ft_tab_max_square(char **s)
{
	int i;
	int j;
	int maxx;
	int maxy;

	j = -1;
	maxx = 0;
	maxy = 0;
	i = -1;
	while (s[++i])
	{
		while (s[i][++j])
		{
			if (s[i][j] != '.')
			{
				maxx = (j > maxx) ? j : maxx;
				maxy = (i > maxy) ? i : maxy;
			}
		}
		j = -1;
	}
	if (maxx >= maxy)
		return (maxx + 1);
	else
		return (maxy + 1);
}

int			ft_next_position(int p, char **tab, t_data *d, t_tetri *t)
{
	int i;
	int j;
	int mod;

	mod = 0;
	i = p % (d->max - 1);
	j = p / (d->max - 1);
	mod = (((t->x[0] > 0) || (t->y[0] > 0)) ? t->x[0] : mod);
	while (tab[j] && (j <= d->max - 1))
	{
		if ((j + t->height) > (d->max - 1))
			return (-1);
		while (tab[j][i] && ((i + t->length) <= (d->max - 1)))
		{
			if (tab[j][i + mod] == '.')
			{
				if (ft_check_positions(tab, t, i, j) == 4)
					return (((d->max - 1) * j) + i);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (-1);
}
