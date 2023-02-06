/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:43:47 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 12:54:53 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->player.move = 0;
	data->player.replacing = '0';
	data->player.facing = 's';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->player.pos_x = j;
				data->player.pos_y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_data(t_data *data, char **argv)
{
	data->map = ft_map_check_and_init(argv[1]);
	data->win_height = data->map.height * 64;
	data->win_width = data->map.width * 64;
	init_player(data, data->map.map);
	pre_path_finding(data);
}

int	main(int argc, char**argv)
{
	t_data	data;

	if (argc != 2)
		arg_error(argc);
	init_data(&data, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, \
	data.win_height, "so_long");
	data.is_img_loaded = init_images(&data, &data.image, data.mlx);
	display_screen(&data);
	mlx_hook(data.win, 2, 0, &press_key, &data);
	mlx_hook(data.win, 17, 0, &red_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
