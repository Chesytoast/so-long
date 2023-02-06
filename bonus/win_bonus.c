/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:32:23 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/18 15:05:07 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_win(t_data *data)
{
	write(1, "Win !\n", 6);
	ft_clean_all(data);
	exit(EXIT_SUCCESS);
}

void	ft_lose(t_data *data)
{
	write(1, "Lose !\n", 7);
	ft_clean_all(data);
	exit(EXIT_SUCCESS);
}
