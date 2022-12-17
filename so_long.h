/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:32 by aplank            #+#    #+#             */
/*   Updated: 2022/12/17 15:44:25 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

typedef struct s_textures
{
	void	*exit_right;
	void	*exit_left;
	void	*bat_right;
	void	*bat_left;
	void	*clover;
	void	*floor;
	void	*wall;
} t_textures;

typedef struct s_map
{
	char	**map;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
} t_map;


//map.c
int 	get_map(t_map *plan, char *map_name);
int		get_p_position(t_map *plan);
void	map_size(t_map *plan);
int		put_map(t_data *window, t_textures *image, t_map *plan);
int		free_map(t_map *plan);

//movement_handling.c
int		get_movement(int keysym, t_map *plan);
int		move_right(t_map *plan);
int		move_down(t_map *plan);
int		move_left(t_map *plan);
int		move_up(t_map *plan);

//textures.c
int		get_textures(t_data *window, t_textures *image);
int		put_image(t_data *window, t_textures *image, t_map *plan);
void	destroy_textures(t_data *window, t_textures *image);

//window_handling.c
int		make_window(t_data *window, t_map *plan);
int		handle_no_event();
int		x_window(t_data *window);
int		key_input(int keysym, t_data *window, t_map *plan);

#endif