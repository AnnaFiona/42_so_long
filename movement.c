/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:48 by aplank            #+#    #+#             */
/*   Updated: 2022/12/19 20:39:50 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_movement(int keysym, t_data *data)
{
	data->move_count++;
	if(keysym == XK_d)
		move_right(data);
	else if(keysym == XK_s)
		move_down(data);
	else if(keysym == XK_a)
		move_left(data);
	else if(keysym == XK_w)
		move_up(data);
	return (0);
}

int	move_right(t_data *data)
{
	data->bat_look = 0;
	if (data->map[data->p_y][data->p_x + 1] == '1')
		return (1);
	if (data->map[data->p_y][data->p_x + 1] == 'C')
		data->clover_count--;
	if (data->map[data->p_y][data->p_x + 1] == 'E')
	{
		if (data->clover_count == 0)
			x_window(data);
		if (data->map[data->p_y][data->p_x + 2] == '1')
			return (1);
		data->map[data->p_y][data->p_x] = '0';
		data->p_x += 2;
		data->map[data->p_y][data->p_x] = 'P';
		return (1);
	}
	data->map[data->p_y][data->p_x] = '0';
	data->map[data->p_y][++data->p_x] = 'P';
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] == '1')
		return (1);
	if (data->map[data->p_y + 1][data->p_x] == 'C')
		data->clover_count--;
	if (data->map[data->p_y + 1][data->p_x] == 'E')
	{
		if (data->clover_count == 0)
			x_window(data);
		if (data->map[data->p_y + 2][data->p_x] == '1')
			return (1);
		data->map[data->p_y][data->p_x] = '0';
		data->p_y += 2;
		data->map[data->p_y][data->p_x] = 'P';
		return (1);
	}
	data->map[data->p_y][data->p_x] = '0';
	data->map[++data->p_y][data->p_x] = 'P';
	return (0);
}

int	move_left(t_data *data)
{
	data->bat_look = 1;
	if (data->map[data->p_y][data->p_x - 1] == '1')
		return (1);
	if (data->map[data->p_y][data->p_x - 1] == 'C')
		data->clover_count--;
	if (data->map[data->p_y][data->p_x - 1] == 'E')
	{
		if (data->clover_count == 0)
			x_window(data);
		if (data->map[data->p_y][data->p_x - 2] == '1')
			return (1);
		data->map[data->p_y][data->p_x] = '0';
		data->p_x -= 2;
		data->map[data->p_y][data->p_x] = 'P';
		return (1);
	}
	data->map[data->p_y][data->p_x] = '0';
	data->map[data->p_y][--data->p_x] = 'P';
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] == '1')
		return (1);
	if (data->map[data->p_y - 1][data->p_x] == 'C')
		data->clover_count--;
	if (data->map[data->p_y - 1][data->p_x] == 'E')
	{
		if (data->clover_count == 0)
			x_window(data);
		if (data->map[data->p_y - 2][data->p_x] == '1')
			return (1);
		data->map[data->p_y][data->p_x] = '0';
		data->p_y -= 2;
		data->map[data->p_y][data->p_x] = 'P';
		return (1);
	}
	data->map[data->p_y][data->p_x] = '0';
	data->map[--data->p_y][data->p_x] = 'P';
	return (0);
}