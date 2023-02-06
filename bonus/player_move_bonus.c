/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:50 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 15:37:57 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_move_up(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'n';
	if (data->map.map[y - 1][x] == '0')
		replace_player_n(data, '0', 'U');
	else if (data->map.map[y - 1][x] == 'C')
	{
		replace_player_n(data, 'C', 'U');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y - 1][x] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		replace_player_n(data, 'E', 'U');
	}
	else if (data->map.map[y - 1][x] == 'B')
		ft_lose(data);
}

void	ft_move_down(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 's';
	if (data->map.map[y + 1][x] == '0')
		replace_player_s(data, '0', 'D');
	else if (data->map.map[y + 1][x] == 'C')
	{
		replace_player_s(data, 'C', 'D');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y + 1][x] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		replace_player_s(data, 'E', 'D');
	}
	else if (data->map.map[y + 1][x] == 'B')
		ft_lose(data);
}

void	ft_move_left(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'e';
	if (data->map.map[y][x - 1] == '0')
		replace_player_e(data, '0', 'L');
	else if (data->map.map[y][x - 1] == 'C')
	{
		replace_player_e(data, 'C', 'L');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y][x - 1] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		replace_player_e(data, 'E', 'L');
	}
	else if (data->map.map[y][x - 1] == 'B')
		ft_lose(data);
}

void	ft_move_right(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'w';
	if (data->map.map[y][x + 1] == '0')
		replace_player_w(data, '0', 'R');
	else if (data->map.map[y][x + 1] == 'C')
	{
		replace_player_w(data, 'C', 'R');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y][x + 1] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		replace_player_w(data, 'E', 'R');
	}
	else if (data->map.map[y][x + 1] == 'B')
		ft_lose(data);
}
