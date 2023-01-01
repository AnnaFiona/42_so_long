/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:40:43 by aplank            #+#    #+#             */
/*   Updated: 2023/01/01 18:37:06 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures_bat(t_data *data)
{
	int	img_height;
	int	img_width;

	data->bat_1_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_1_right.xpm", &img_width, &img_height);
	data->bat_1_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_1_left.xpm", &img_width, &img_height);
	data->bat_2_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_2_right.xpm", &img_width, &img_height);
	data->bat_2_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_2_left.xpm", &img_width, &img_height);
	data->bat_3_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_3_right.xpm", &img_width, &img_height);
	data->bat_3_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_3_left.xpm", &img_width, &img_height);
	data->bat_4_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_4_right.xpm", &img_width, &img_height);
	data->bat_4_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_4_left.xpm", &img_width, &img_height);
	data->bat_5_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_5_right.xpm", &img_width, &img_height);
	data->bat_5_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/bat_5_left.xpm", &img_width, &img_height);
}

void	put_bat_right(t_data *data)
{
	data->bat_animation_cnt++;
	if (data->bat_animation_cnt < 4000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_1_right,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 7000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_2_right,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 10000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_3_right,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 13000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_4_right,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 16500)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_5_right,
			data->p_x * 40, data->p_y * 40);
	if (data->bat_animation_cnt >= 16500)
		data->bat_animation_cnt = 0;
}

void	put_bat_left(t_data *data)
{
	data->bat_animation_cnt++;
	if (data->bat_animation_cnt < 4000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_1_left,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 7000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_2_left,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 10000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_3_left,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 12000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_4_left,
			data->p_x * 40, data->p_y * 40);
	else if (data->bat_animation_cnt < 16500)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->bat_5_left,
			data->p_x * 40, data->p_y * 40);
	if (data->bat_animation_cnt >= 16500)
		data->bat_animation_cnt = 0;
}
