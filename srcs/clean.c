/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:49:49 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 13:48:59 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	ft_clean_img(t_data *data)
{
	if (data->image.ground)
		mlx_destroy_image(data->mlx, data->image.ground);
	if (data->image.wall)
		mlx_destroy_image(data->mlx, data->image.wall);
	if (data->image.coll)
		mlx_destroy_image(data->mlx, data->image.coll);
	if (data->image.exit)
		mlx_destroy_image(data->mlx, data->image.exit);
	if (data->image.player_n)
		mlx_destroy_image(data->mlx, data->image.player_n);
	if (data->image.player_s)
		mlx_destroy_image(data->mlx, data->image.player_s);
	if (data->image.player_e)
		mlx_destroy_image(data->mlx, data->image.player_e);
	if (data->image.player_w)
		mlx_destroy_image(data->mlx, data->image.player_w);
}

void	ft_clean_all(t_data *data)
{
	if (data->map.map)
		ft_free_tab(data->map.map);
	if (data->is_img_loaded == 1)
		ft_clean_img(data);
	if (data->win)
		mlx_clear_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_window(data->mlx, data->win);
}

void	ft_clean_path(t_data *data)
{
	if (data->map.map)
		ft_free_tab(data->map.map);
}
