/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:31:48 by aplank            #+#    #+#             */
/*   Updated: 2022/12/17 16:38:40 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_movement(int keysym, t_map *plan)
{
	/* plan->p_y = 2;
	plan->p_x = 2; */
	printf("get_movement p_x: %d		p_y: %d\n", plan->p_x, plan->p_y);
	if(keysym == XK_d)
		move_right(plan);
	else if(keysym == XK_s)
		move_down(plan);
	else if(keysym == XK_a)
		move_left(plan);
	else if(keysym == XK_w)
		move_up(plan);
	return (0);
}

int	move_right(t_map *plan)
{
	printf("move_right p_x: %d		p_y: %d\n", plan->p_x, plan->p_y);
/* 	if (plan->map[plan->p_y][plan->p_x + 1] == '1')
		return (1);
	plan->map[plan->p_y][plan->p_x] = '0';
	plan->p_x++;
	plan->map[plan->p_y][plan->p_x] = 'P'; */
	return (0);
}

int	move_down(t_map *plan)
{
	if (plan->map[plan->p_y + 1][plan->p_x] == '1')
		return (1);
	plan->map[plan->p_y][plan->p_x] = '0';
	plan->map[++plan->p_y][plan->p_x] = 'P';
	return (0);
}

int	move_left(t_map *plan)
{
	if (plan->map[plan->p_y][plan->p_x - 1] == '1')
		return (1);
	plan->map[plan->p_y][plan->p_x] = '0';
	plan->map[plan->p_y][--plan->p_x] = 'P';
	return (0);
}

int	move_up(t_map *plan)
{
	if (plan->map[plan->p_y - 1][plan->p_x] == '1')
		return (1);
	plan->map[plan->p_y][plan->p_x] = '0';
	plan->map[--plan->p_y][plan->p_x] = 'P';
	return (0);
}