/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:48:45 by aplank            #+#    #+#             */
/*   Updated: 2022/12/13 18:51:53 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event()
{
	return(0);
}

int	x_window(t_data *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	return (0);
}

int	close_window(int keysym, t_data *window)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	return (0);
}