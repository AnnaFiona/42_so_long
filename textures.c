/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:39:36 by aplank            #+#    #+#             */
/*   Updated: 2023/01/01 17:43:38 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_textures(t_data *data)
{
	int	img_height;
	int	img_width;

	get_textures_bat(data);
	data->exit_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/CrazyWizard_on_green_right.xpm", &img_width, &img_height);
	data->exit_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/CrazyWizard_on_green_left.xpm", &img_width, &img_height);
	data->clover = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/clover_on_green.xpm", &img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/greenish_floor.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./images/black_wall.xpm",
			&img_width, &img_height);
	return (0);
}

int	put_image(t_data *data)
{
	if (data->map[data->y][data->x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor,
			data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,
			data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->clover,
			data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'E' && data->p_x <= data->e_x)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_left,
			data->x * 40, data->y * 40);
	else if (data->map[data->y][data->x] == 'E' && data->p_x > data->e_x)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit_right,
			data->x * 40, data->y * 40);
	return (0);
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
