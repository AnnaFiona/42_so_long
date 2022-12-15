/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:39:36 by aplank            #+#    #+#             */
/*   Updated: 2022/12/15 16:15:28 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_textures(t_data *window, t_textures *image)
{
	int			img_height;
	int			img_width;
	

	image->exit_right = mlx_xpm_file_to_image(window->mlx_ptr, "./images/CrazyWizard_on_green_right.xpm", &img_width, &img_height);
	image->exit_left = mlx_xpm_file_to_image(window->mlx_ptr, "./images/CrazyWizard_on_green_left.xpm", &img_width, &img_height);
	image->bat_right = mlx_xpm_file_to_image(window->mlx_ptr, "./images/bat_on_green_right.xpm", &img_width, &img_height);
	image->bat_left = mlx_xpm_file_to_image(window->mlx_ptr, "./images/bat_on_green_left.xpm", &img_width, &img_height);
	image->clover = mlx_xpm_file_to_image(window->mlx_ptr, "./images/clover_on_green.xpm", &img_width, &img_height);
	image->floor = mlx_xpm_file_to_image(window->mlx_ptr, "./images/greenish_floor.xpm", &img_width, &img_height);
	image->wall = mlx_xpm_file_to_image(window->mlx_ptr, "./images/black_wall.xpm", &img_width, &img_height);
	return (0);
}

int put_image(t_data *window, t_textures *image, t_map *plan)
{
	if (plan->map[plan->y][plan->x] == '0')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->floor, plan->x * 40, plan->y * 40);
	else if (plan->map[plan->y][plan->x] == '1')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->wall, plan->x * 40, plan->y * 40);
	else if (plan->map[plan->y][plan->x] == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->clover, plan->x * 40, plan->y * 40);
	else if (plan->map[plan->y][plan->x] == 'P')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->bat_right, plan->x * 40, plan->y * 40);
	else if (plan->map[plan->y][plan->x] == 'E')
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->exit_right, plan->x * 40, plan->y * 40);

	return (0);
}

void	destroy_textures(t_data *window, t_textures *image)
{
	mlx_destroy_image(window->mlx_ptr, image->exit_right);
	mlx_destroy_image(window->mlx_ptr, image->exit_left);
	mlx_destroy_image(window->mlx_ptr, image->bat_right);
	mlx_destroy_image(window->mlx_ptr, image->bat_left);
	mlx_destroy_image(window->mlx_ptr, image->floor);
	mlx_destroy_image(window->mlx_ptr, image->wall);
}

/* 	int			x;
	int			y;

	y = 0;
	//mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->bat, 0, 0);
	while(y <= 360)
	{
		x = 0;
		while (x <= 760)
		{
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, image->exit_left, x, y);
			x += 40;
		}
		y += 40;
	}
	return (0); */