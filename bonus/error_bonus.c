/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:26:52 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 14:41:29 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	arg_error(int argc)
{
	write(2, "Error\n", 6);
	if (argc > 2)
		write(2, "Too many arguments\n", 19);
	if (argc < 2)
		write(2, "Not enough arguments\n", 21);
	exit (EXIT_FAILURE);
}

void	map_error(int errnb, char **map)
{
	write(2, "Error\n", 6);
	if (errnb == 1)
		write(2, "map needs to be a '.ber' file\n", 30);
	if (errnb == 2)
		write(2, "Not enough collectible\n", 23);
	if (errnb == 3)
		write(2, "Wrong exit number\n", 18);
	if (errnb == 4)
		write(2, "Wrong entry number\n", 19);
	if (errnb == 5)
		write(2, "Map is not a rectangle\n", 23);
	if (errnb == 6)
		write(2, "Wrong charachter in the map file\n", 33);
	if (errnb == 7)
		write(2, "Map is not walled correctly\n", 28);
	if (errnb == 8)
		write(2, "The map file does not exist\n", 28);
	if (errnb > 1 && errnb < 8)
		ft_free_tab(map);
	exit (EXIT_FAILURE);
}

void	img_error(t_data *data, void *img)
{
	if (!img)
	{
		ft_clean_all(data);
		exit(EXIT_FAILURE);
	}
}

void	path_error(t_data *data)
{
	ft_clean_path(data);
	write(2, "Error\n", 6);
	write(2, "The map as no correct path thus is unplayable.\n", 47);
	exit(EXIT_FAILURE);
}

void	empty_error(char *ber_map)
{
	free(ber_map);
	write(2, "Error\n", 6);
	write(2, "Can not have empty line in map file\n", 36);
	exit(EXIT_FAILURE);
}
