/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:53:48 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 20:43:50 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *tab)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < 4)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}

char	**ft_copytab(char **src)
{
	char	**tab;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		tab[i] = ft_strdup(src[i]);
		i++;
	}
	return (tab);
}

void	ft_cut_tab(char **tab, int max)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i][max] = '\0';
		++i;
	}
	tab[max] = NULL;
}

int		ft_check_positions(char **tab, t_tetri *t, int i, int j)
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

void	ft_coor_init(int *x, int *y, int p, t_data *d)
{
	*x = p % (d->max - 1);
	*y = p / (d->max - 1);
}
