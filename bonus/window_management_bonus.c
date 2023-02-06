/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:27:36 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 14:24:39 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	init_images(t_data *data, t_images *image, void *mlx)
{
	int	width;
	int	height;

	img_error(data, image->player_n = mlx_xpm_file_to_image(mlx, \
	"img/pengu_back.xpm", &width, &height));
	img_error(data, image->player_s = mlx_xpm_file_to_image(mlx, \
	"img/pengu_face.xpm", &width, &height));
	img_error(data, image->player_e = mlx_xpm_file_to_image(mlx, \
	"img/pengu_right.xpm", &width, &height));
	img_error(data, image->player_w = mlx_xpm_file_to_image(mlx, \
	"img/pengu_left.xpm", &width, &height));
	img_error(data, image->ground = mlx_xpm_file_to_image(mlx, \
	"img/ice_texture.xpm", &width, &height));
	img_error(data, image->wall = mlx_xpm_file_to_image(mlx, \
	"img/water.xpm", &width, &height));
	img_error(data, image->exit = mlx_xpm_file_to_image(mlx, \
	"img/igloo.xpm", &width, &height));
	img_error(data, image->coll = mlx_xpm_file_to_image(mlx, \
	"img/shrimp.xpm", &width, &height));
	img_error(data, image->bear = mlx_xpm_file_to_image(mlx, \
	"img/polar_bear.xpm", &width, &height));
	return (1);
}

static void	put_player(t_data *data, int i, int j, char c)
{
	if (c == 'P' && data->player.facing == 's')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.player_s, j * 64, i * 64);
	if (c == 'P' && data->player.facing == 'n')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.player_n, j * 64, i * 64);
	if (c == 'P' && data->player.facing == 'w')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.player_e, j * 64, i * 64);
	if (c == 'P' && data->player.facing == 'e')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.player_w, j * 64, i * 64);
}

static void	put_image(t_data *data, int i, int j)
{
	char	c;

	c = data->map.map[i][j];
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.wall, j * 64, i * 64);
	if (c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'B')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.ground, j * 64, i * 64);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.coll, j * 64 + 32, i * 64 + 32);
	if (c == 'E' || (c == 'P' && data->player.replacing == 'E'))
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.exit, j * 64, i * 64);
	if (c == 'P')
		put_player(data, i, j, c);
	if (c == 'B')
		mlx_put_image_to_window(data->mlx, data->win, \
		data->image.bear, j * 64, i * 64);
}

void	display_screen(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			put_image(data, i, j);
			j++;
		}
		i++;
	}
	mlx_string_put(data->mlx, data->win, (data->win_width / 2), 20, 0x00FF0000, \
	ft_itoa(data->player.move));
}
