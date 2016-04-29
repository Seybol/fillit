/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:53:46 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/18 20:38:14 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_test(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	if (str[i] == '#')
		if (str[i + 1] == '#')
			if (str[i + 10] == '#')
				if (str[i + 11] == '#')
					return (0);
	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	if (str[i] == '#')
		if (str[i + 2] == '#')
			if (str[i + 5] == '#')
				if (str[i + 7] == '#')
					return (0);
	return (1);
}
