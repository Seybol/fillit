/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:41:13 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 20:02:28 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_final_check(int imin, int imax, int jmin, int jmax)
{
	if (((imax - imin == 1) && (jmax - jmin == 1)) ||
			((imax - imin == 2) && (jmax - jmin == 1)) ||
			((imax - imin == 1) && (jmax - jmin == 2)) ||
			(imax == imin && (jmax - jmin == 3)) ||
			(jmax == jmin && (imax - imin == 3)))
		return (1);
	return (0);
}

static int	ft_char_is_ok(char *str)
{
	int lines;
	int tetri;
	int notetri;

	lines = 0;
	tetri = 0;
	notetri = 0;
	while (*str)
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		if (*str == '\n')
			++lines;
		if (*str == '#')
			++tetri;
		if (*str == '.')
			++notetri;
		++str;
	}
	if ((lines == 5 || lines == 4) && tetri == 4 && notetri == 12)
		return (1);
	return (0);
}

static void	ft_initv(int *a, int *b, int *c, int *d)
{
	*a = 3;
	*b = 0;
	*c = 3;
	*d = 0;
}

static int	ft_check_form(char *s)
{
	int imin;
	int imax;
	int jmin;
	int jmax;
	int i;

	ft_initv(&imin, &imax, &jmin, &jmax);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '#')
		{
			imin = ((i % 5) < imin) ? (i % 5) : imin;
			imax = ((i % 5) > imax) ? (i % 5) : imax;
			jmin = ((i / 5) < jmin) ? (i / 5) : jmin;
			jmax = ((i / 5) > jmax) ? (i / 5) : jmax;
		}
	}
	return (ft_final_check(imin, imax, jmin, jmax));
}

int			ft_check_list(t_list **begin_list)
{
	t_list	*explorer;
	char	*str;

	explorer = *begin_list;
	while (explorer)
	{
		str = explorer->content;
		if (!ft_char_is_ok(str))
			return (0);
		str = explorer->content;
		if (explorer->next != NULL &&
				(str[4] != '\n' || str[9] != '\n' || str[14] != '\n'
				|| str[19] != '\n' || str[20] != '\n'))
			return (0);
		if (explorer->next == NULL &&
				(((str[4] != '\n' || str[9] != '\n' || str[14] != '\n'
				|| str[19] != '\n' || str[20] != '\0'))))
			return (0);
		str = explorer->content;
		if (!ft_check_form(str) || !ft_test(str))
			return (0);
		explorer = explorer->next;
	}
	return (1);
}
