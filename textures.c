/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:39:36 by aplank            #+#    #+#             */
/*   Updated: 2022/12/29 12:37:39 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_textures(t_data *data)
{
	int			img_height;
	int			img_width;
	
	data->exit_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/CrazyWizard_on_green_right.xpm", &img_width, &img_height);
	data->exit_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/CrazyWizard_on_green_left.xpm", &img_width, &img_height);
	data->bat_1_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_1_right.xpm", &img_width, &img_height);
	data->bat_1_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_1_left.xpm", &img_width, &img_height);
	data->bat_2_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_2_right.xpm", &img_width, &img_height);
	data->bat_2_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_2_left.xpm", &img_width, &img_height);
	data->bat_3_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_3_right.xpm", &img_width, &img_height);
	data->bat_3_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_3_left.xpm", &img_width, &img_height);
	data->bat_4_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_4_right.xpm", &img_width, &img_height);
	data->bat_4_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_4_left.xpm", &img_width, &img_height);
	data->bat_5_right = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_5_right.xpm", &img_width, &img_height);
	data->bat_5_left = mlx_xpm_file_to_image(data->mlx_ptr, "./images/bat_5_left.xpm", &img_width, &img_height);
	data->clover = mlx_xpm_file_to_image(data->mlx_ptr, "./images/clover_on_green.xpm", &img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "./images/greenish_floor.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./images/black_wall.xpm", &img_width, &img_height);
	return (0);
}

int put_image(t_data *data)
{
	if (data->map[data->y][data->x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->clover, data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'E' && data->p_x <= data->e_x)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_left, data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'E' && data->p_x > data->e_x)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_right, data->x * 40, data->y * 40);
	return (0);
}

void	put_bat_right(t_data *data)
{
	data->bat_animation_cnt++;
	if (data->bat_animation_cnt < 900)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_1_right, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 1800)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_2_right, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 2700)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_3_right, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 3600)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_4_right, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 4500)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_5_right, data->p_x * 40, data->p_y * 40);
	if (data->bat_animation_cnt >= 4500)
		data->bat_animation_cnt = 0;
}

void	put_bat_left(t_data *data)
{
	data->bat_animation_cnt++;
	if (data->bat_animation_cnt < 1000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_1_left, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 2000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_2_left, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 3000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_3_left, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 4000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_4_left, data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 5000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_5_left, data->p_x * 40, data->p_y * 40);
	if (data->bat_animation_cnt >= 5000)
		data->bat_animation_cnt = 0;
}

void	destroy_textures(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->exit_right);
	mlx_destroy_image(data->mlx_ptr, data->exit_left);
	mlx_destroy_image(data->mlx_ptr, data->bat_1_right);
	mlx_destroy_image(data->mlx_ptr, data->bat_1_left);
	mlx_destroy_image(data->mlx_ptr, data->bat_2_right);
	mlx_destroy_image(data->mlx_ptr, data->bat_2_left);
	mlx_destroy_image(data->mlx_ptr, data->bat_3_right);
	mlx_destroy_image(data->mlx_ptr, data->bat_3_left);
	mlx_destroy_image(data->mlx_ptr, data->bat_4_right);
	mlx_destroy_image(data->mlx_ptr, data->bat_4_left);
	mlx_destroy_image(data->mlx_ptr, data->bat_5_right);
	mlx_destroy_image(data->mlx_ptr, data->bat_5_left);
	mlx_destroy_image(data->mlx_ptr, data->clover);
	mlx_destroy_image(data->mlx_ptr, data->floor);
	mlx_destroy_image(data->mlx_ptr, data->wall);
}
