/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:20:05 by aplank            #+#    #+#             */
/*   Updated: 2023/01/01 18:13:33 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x * 40, data->win_y
			* 40, "test_window");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	return (0);
}

int	x_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = 0;
	return (0);
}

int	key_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (1);
	}
	else if (keysym == XK_d || keysym == XK_s || keysym == XK_a
		|| keysym == XK_w)
		get_movement(keysym, data);
	return (0);
}
