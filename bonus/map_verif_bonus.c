/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:19 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 19:10:59 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_e_c_p(t_map map)
{
	if (map.collectible <= 0)
		map_error(2, map.map);
	if (map.exit != 1)
		map_error(3, map.map);
	if (map.entry != 1)
		map_error(4, map.map);
}

void	is_map_rectangle(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		if ((int)ft_strlen(map.map[i]) != map.width)
			map_error(5, map.map);
		i++;
	}
}

int	is_charachter(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "01CPEB";
	while (str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

void	is_map_goodcharachter(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (is_charachter(map.map[i][j]) == 1)
				map_error(6, map.map);
			j++;
		}
		i++;
	}
}

void	is_map_walled(t_map map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map.map[0][j])
	{
		if (map.map[0][j++] != '1')
			map_error(7, map.map);
	}
	while (map.map[i])
	{
		if (map.map[i][0] != '1')
			map_error(7, map.map);
		if (map.map[i][map.width - 1] != '1')
			map_error(7, map.map);
		i++;
	}
	j = 0;
	i -= 1;
	while (map.map[i][j])
	{
		if (map.map[i][j++] != '1')
			map_error(7, map.map);
	}
}
