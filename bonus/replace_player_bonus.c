/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:10:18 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 16:23:37 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	replace_player_n(t_data *data, char replacing, char mvt)
{
	data->map.map[data->player.pos_y - 1][data->player.pos_x] = 'P';
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
}

void	replace_player_s(t_data *data, char replacing, char mvt)
{
	data->map.map[data->player.pos_y + 1][data->player.pos_x] = 'P';
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
}

void	replace_player_e(t_data *data, char replacing, char mvt)
{
	data->map.map[data->player.pos_y][data->player.pos_x - 1] = 'P';
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
}

void	replace_player_w(t_data *data, char replacing, char mvt)
{
	data->map.map[data->player.pos_y][data->player.pos_x + 1] = 'P';
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
}
