/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:27:07 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 14:42:09 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_read_ber(int fd)
{
	int		ret;
	char	*buffer;
	char	*map;

	ret = 1;
	map = NULL;
	buffer = malloc(sizeof(char) * (256 + 1));
	if (!buffer)
		return (NULL);
	while (ret != 0)
	{
		ret = read(fd, buffer, 256);
		if (ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = '\0';
		map = ft_strjoin(map, buffer);
		if (!map)
			return (NULL);
	}
	free(buffer);
	return (map);
}

void	empty_line(char	*ber_map)
{
	int	i;

	i = 0;
	while (ber_map[i])
	{
		if ((ber_map[i] == '\n' && (ber_map[i + 1] == \
		'\n' || ber_map[i + 1] == '\0')) || ber_map[0] == '\n')
			empty_error(ber_map);
		i++;
	}
}

void	init_map(char *ber_map, t_map *map)
{
	int	i;

	i = 0;
	empty_line(ber_map);
	map->collectible = 0;
	map->entry = 0;
	map->exit = 0;
	map->map = ft_split(ber_map, '\n');
	map->height = 1;
	map->width = ft_strlen(map->map[0]);
	while (ber_map[i])
	{
		if (ber_map[i] == 'C')
			map->collectible += 1;
		if (ber_map[i] == 'E')
			map->exit += 1;
		if (ber_map[i] == 'P')
			map->entry += 1;
		if (ber_map[i] == '\n')
			map->height += 1;
		i++;
	}
	free(ber_map);
}

t_map	ft_map_check_and_init(char *argv)
{
	t_map	map;
	int		i;
	int		fd;
	char	*ber_map;

	i = ft_strlen(argv) - 4;
	if (i < 0)
		map_error(1, map.map);
	if (ft_strncmp(&argv[i], ".ber", 4) != 0)
		map_error(1, map.map);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		map_error(8, map.map);
	ber_map = ft_read_ber(fd);
	close(fd);
	init_map(ber_map, &map);
	check_e_c_p(map);
	is_map_rectangle(map);
	is_map_goodcharachter(map);
	is_map_walled(map);
	return (map);
}
