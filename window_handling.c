/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:45 by aplank            #+#    #+#             */
/*   Updated: 2022/12/17 15:39:35 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_window(t_data *window, t_map *plan)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		return (1);
	window->win_ptr = mlx_new_window(window->mlx_ptr, plan->x * 40, plan->y * 40, "test_window");
	if (window->win_ptr == NULL)
	{
		free(window->win_ptr);
		return (1);
	}
	return (0);
}

int	handle_no_event()
{
	return(0);
}

int	x_window(t_data *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	return (0);
}

int	key_input(int keysym, t_data *window, t_map *plan)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	else
		get_movement(keysym, plan);
	return (0);
}