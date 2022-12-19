/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:32 by aplank            #+#    #+#             */
/*   Updated: 2022/12/19 16:56:28 by aplank           ###   ########.fr       */
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

	void	*exit_right;
	void	*exit_left;
	void	*bat_right;
	void	*bat_left;
	void	*clover;
	void	*floor;
	void	*wall;
	
	int		clover_count;
	int		bat_look;
	char	**map;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		x;
	int		y;
} t_data;

/* typedef struct s_textures
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
} t_map; */


//map.c
int 	get_map(t_data *data, char *map_name);
int		get_p_position(t_data *data);
int		get_e_position(t_data *data);
int		get_positions(t_data *data);
void	map_size(t_data *data);
int		put_map(t_data *data);
int		free_map(t_data *data);

//movement_handling.c
int		get_movement(int keysym, t_data *data);
int		move_right(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_up(t_data *data);

//textures.c
int		get_textures(t_data *data);
int		put_image(t_data *data);
void	destroy_textures(t_data *data);

//window_handling.c
int		make_window(t_data *data);
int		x_window(t_data *data);
int		key_input(int keysym, t_data *data);

#endif