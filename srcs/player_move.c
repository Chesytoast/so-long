/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:50 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 16:04:04 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	replace_player(t_data *data, char replacing, char mvt)
{
	if (data->player.replacing == '0')
		data->map.map[data->player.pos_y][data->player.pos_x] = '0';
	if (data->player.replacing == 'C')
		data->map.map[data->player.pos_y][data->player.pos_x] = '0';
	if (data->player.replacing == 'E')
		data->map.map[data->player.pos_y][data->player.pos_x] = 'E';
	data->player.replacing = replacing;
	if (mvt == 'U')
		data->player.pos_y -= 1;
	if (mvt == 'D')
		data->player.pos_y += 1;
	if (mvt == 'L')
		data->player.pos_x -= 1;
	if (mvt == 'R')
		data->player.pos_x += 1;
	data->player.move += 1;
	ft_putnbr_fd(data->player.move, 1);
	write(1, "\n", 1);
}

void	ft_move_up(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'n';
	if (data->map.map[y - 1][x] == '0')
	{
		data->map.map[y - 1][x] = 'P';
		replace_player(data, '0', 'U');
	}
	else if (data->map.map[y - 1][x] == 'C')
	{
		data->map.map[y - 1][x] = 'P';
		replace_player(data, 'C', 'U');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y - 1][x] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		data->map.map[y - 1][x] = 'P';
		replace_player(data, 'E', 'U');
	}
}

void	ft_move_down(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 's';
	if (data->map.map[y + 1][x] == '0')
	{
		data->map.map[y + 1][x] = 'P';
		replace_player(data, '0', 'D');
	}
	else if (data->map.map[y + 1][x] == 'C')
	{
		data->map.map[y + 1][x] = 'P';
		replace_player(data, 'C', 'D');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y + 1][x] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		data->map.map[y + 1][x] = 'P';
		replace_player(data, 'E', 'D');
	}
}

void	ft_move_left(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'e';
	if (data->map.map[y][x - 1] == '0')
	{
		data->map.map[y][x - 1] = 'P';
		replace_player(data, '0', 'L');
	}
	else if (data->map.map[y][x - 1] == 'C')
	{
		data->map.map[y][x - 1] = 'P';
		replace_player(data, 'C', 'L');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y][x - 1] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		data->map.map[y][x - 1] = 'P';
		replace_player(data, 'E', 'L');
	}
}

void	ft_move_right(t_data *data)
{
	int		x;
	int		y;

	x = data->player.pos_x;
	y = data->player.pos_y;
	data->player.facing = 'w';
	if (data->map.map[y][x + 1] == '0')
	{
		data->map.map[y][x + 1] = 'P';
		replace_player(data, '0', 'R');
	}
	else if (data->map.map[y][x + 1] == 'C')
	{
		data->map.map[y][x + 1] = 'P';
		replace_player(data, 'C', 'R');
		data->map.collectible -= 1;
	}
	else if (data->map.map[y][x + 1] == 'E')
	{
		if (data->map.collectible == 0)
			ft_win(data);
		data->map.map[y][x + 1] = 'P';
		replace_player(data, 'E', 'R');
	}
}
