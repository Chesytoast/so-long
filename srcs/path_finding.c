/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:07:48 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 13:53:59 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_cpy(t_data *data)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (data->map.height + 1));
	if (!map)
		return (NULL);
	while (i < data->map.height)
	{
		map[i] = ft_strdup(data->map.map[i]);
		if (!map[i++])
		{
			ft_free_tab(map);
			ft_clean_all(data);
		}
	}
	map[i] = NULL;
	return (map);
}

void	pre_path_finding(t_data *data)
{
	t_path	path;
	char	**map;
	int		i;
	int		j;
	int		res;

	map = map_cpy(data);
	i = data->player.pos_y;
	j = data->player.pos_x;
	path.collectable = data->map.collectible;
	path.exit = 1;
	res = path_finding(map, i, j, &path);
	ft_free_tab(map);
	if (res != 1)
		path_error(data);
}

int	path_finding(char **map, int i, int j, t_path *path)
{
	if (map)
	{
		if (map[i][j] == '1')
			return (0);
		if (map[i][j] == 'C')
			path->collectable--;
		if (map[i][j] == 'E')
			path->exit--;
		map[i][j] = '1';
		(path_finding(map, i + 1, j, path)
			|| path_finding(map, i - 1, j, path)
			|| path_finding(map, i, j + 1, path)
			|| path_finding(map, i, j - 1, path));
		return (path->collectable == 0 && path->exit == 0);
	}
	return (0);
}
