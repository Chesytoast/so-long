/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtin <mcourtin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:00 by mcourtin          #+#    #+#             */
/*   Updated: 2023/01/20 13:49:50 by mcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

// key "assignation"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

//struct :

typedef struct s_path
{
	int	collectable;
	int	exit;
}	t_path;

typedef struct s_map
{
	char	**map;
	int		entry;
	int		exit;
	int		collectible;
	int		width;
	int		height;
}	t_map;

typedef struct s_images
{
	void	*player_n;
	void	*player_s;
	void	*player_e;
	void	*player_w;
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coll;
}	t_images;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		move;
	char	replacing;
	char	facing;
}	t_player;

typedef struct s_data
{
	t_map		map;
	t_images	image;
	t_player	player;
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			is_img_loaded;
}	t_data;

//utils :
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s1);

//error + clean :
void	map_error(int errnb, char **map);
void	arg_error(int argc);
void	ft_free_tab(char **tab);
void	ft_clean_all(t_data *data);
void	img_error(t_data *data, void *img);
void	path_error(t_data *data);
void	empty_error(char *ber_map);
void	ft_clean_path(t_data *data);

//map :
t_map	ft_map_check_and_init(char *argv);
char	*ft_read_ber(int fd);
void	init_map(char *ber_map, t_map *map);

//window management :
int		init_images(t_data *data, t_images *image, void *mlx);
void	display_screen(t_data *data);

//map verif :
void	check_e_c_p(t_map map);
void	is_map_rectangle(t_map map);
void	is_map_goodcharachter(t_map map);
int		is_charachter(char c);
void	is_map_walled(t_map map);

//path :
void	pre_path_finding(t_data *data);
int		path_finding(char **map, int i, int j, t_path *path);

//window management :
void	window_management(t_data data);
int		red_cross(t_data *data);

//movement :
void	ft_win(t_data *data);
int		press_key(int key, t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
void	replace_player(t_data *data, char replacing, char mvt);

#endif