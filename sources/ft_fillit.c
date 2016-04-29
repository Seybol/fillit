/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <scebula@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:42:11 by scebula           #+#    #+#             */
/*   Updated: 2016/01/18 20:42:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		++i;
	}
}

static char		**ft_create_tab(void)
{
	char	**tab;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * (21))))
		return (NULL);
	while (++i < 21)
	{
		tab[i] = ft_strnew(21);
		while (++j < 21)
			tab[i][j] = '.';
		j = -1;
	}
	return (tab);
}

static t_data	*ft_data_init(void)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->max = 0;
	new->max_found = 0;
	new->tabmax = NULL;
	return (new);
}

void			ft_fillit(char **tab, t_tetri *t, t_data *d)
{
	d = ft_data_init();
	d->max = 2;
	while (d->tabmax == NULL)
	{
		tab = ft_create_tab();
		ft_algo(0, t, tab, d);
		++d->max;
	}
	ft_cut_tab(d->tabmax, d->max - 1);
	ft_print_tab(d->tabmax);
}

int				main(int argc, char **argv)
{
	t_list	*list;
	t_tetri	*t;
	int		fd;
	char	**tab;
	t_data	*d;

	ft_initnull(&fd, &list, &t, &d);
	tab = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
			if (!ft_data_to_list(&list, fd))
				fd = -1;
		if (ft_check_list(&list) && fd != -1)
		{
			ft_create_t_tetri(&list, &t, 'A');
			ft_fillit(tab, t, d);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
