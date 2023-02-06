/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:08 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 15:00:03 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	press_key(int key, t_data *data)
{
	if (key == ESC)
	{
		ft_clean_all(data);
		exit(EXIT_SUCCESS);
	}
	if (key == W)
		ft_move_up(data);
	if (key == A)
		ft_move_left(data);
	if (key == D)
		ft_move_right(data);
	if (key == S)
		ft_move_down(data);
	mlx_clear_window(data->mlx, data->win);
	display_screen(data);
	return (0);
}

int	red_cross(t_data *data)
{
	ft_clean_all(data);
	exit(EXIT_SUCCESS);
}
