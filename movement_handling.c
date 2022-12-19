/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:48 by aplank            #+#    #+#             */
/*   Updated: 2022/12/19 14:30:33 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_movement(int keysym, t_data *data)
{
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
	if (data->map[data->p_y][data->p_x + 1] == '1')
		return (1);
	//if (data->map[data->p_y][data->p_x + 1] == 'E')
	data->map[data->p_y][data->p_x] = '0';
	data->p_x++;
	data->map[data->p_y][data->p_x] = 'P';
	data->bat_look = 0;
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->p_y + 1][data->p_x] == '1')
		return (1);
	data->map[data->p_y][data->p_x] = '0';
	data->map[++data->p_y][data->p_x] = 'P';
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map[data->p_y][data->p_x - 1] == '1')
		return (1);
	data->map[data->p_y][data->p_x] = '0';	if (data->p_x <= data->e_x)
		data->bat_look = 0;
	else
		data->bat_look = 1;
	data->map[data->p_y][--data->p_x] = 'P';
	data->bat_look = 1;
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->p_y - 1][data->p_x] == '1')
		return (1);
	data->map[data->p_y][data->p_x] = '0';
	data->map[--data->p_y][data->p_x] = 'P';
	return (0);
}