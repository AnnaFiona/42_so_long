/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:32 by aplank            #+#    #+#             */
/*   Updated: 2023/01/02 19:50:30 by aplank           ###   ########.fr       */
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
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*exit_right;
	void	*exit_left;
	int		bat_animation_cnt;
	void	*bat_1_right;
	void	*bat_1_left;
	void	*bat_2_right;
	void	*bat_2_left;
	void	*bat_3_right;
	void	*bat_3_left;
	void	*bat_4_right;
	void	*bat_4_left;
	void	*bat_5_right;
	void	*bat_5_left;
	void	*clover;
	void	*floor;
	void	*wall;

	int		clover_count;
	int		move_count;
	int		bat_look;
	char	*map_name;
	char	**map;
	char	*buf;
	int		win_x;
	int		win_y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		x;
	int		y;
}	t_data;

typedef struct s_check
{
	int		exit_reach;
	int		clover_cnt;
	int		player_cnt;
	int		exit_cnt;
	char	**map;
	int		p_x;
	int		p_y;

}	t_check;

//check.c
int		check(t_data *data);
void	check_count(t_check *check);
int		put_error(t_data *data, t_check *check);
void	free_check(t_check *check);

//map_check.c
void	check_map(t_data *data, t_check *check);
int		field_check(t_check *check, int x, int y);
int		check_size_and_characters(t_check *check);
int		check_characters(t_check *check, int y);
int		check_border(t_data *data, t_check *check);

//map.c
int		read_map(t_data *data);
int		get_map(t_data *data);
void	get_positions(t_data *data);
int		put_map(t_data *data);
int		free_map(t_data *data);

//movement.c
int		get_movement(int keysym, t_data *data);
int		move_right(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_up(t_data *data);

//textures_bat.c
void	get_textures_bat(t_data *data);
void	put_bat_right(t_data *data);
void	put_bat_left(t_data *data);

//textures.c
int		get_textures(t_data *data);
int		put_image(t_data *data);
void	destroy_textures(t_data *data);

//window_handling.c
int		make_window(t_data *data);
int		x_window(t_data *data);
int		key_input(int keysym, t_data *data);

#endif