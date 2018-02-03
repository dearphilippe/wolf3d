/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 08:55:03 by passef            #+#    #+#             */
/*   Updated: 2018/02/02 17:04:10 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

t_env	*init_e(void)
{
	t_env	*e;
	
	if (!(e = malloc(sizeof(*e))))
		return (NULL);
	e->mlx_ptr = NULL;
	e->mlx_win = NULL;
	e->w_screen = 640;
	e->h_screen = 380;
	e->keydown = 125;
	e->keyup = 126;
	e->mousedown = 124;
	e->mouseup = 123;
	e->mousemove = 0;
	e->expose = 12;
	e->close = 17;
	return (e);
}

int		handle_key(int key, t_env *e)
{
	if (key == e->keydown)
		printf("down\n");
	if (key == e->keyup)
		printf("up\n");
	if (key == e->mousedown)
		printf("right\n");
	if (key == e->mouseup)
		printf("left\n");
	if (key == e->mousemove)
		printf("A\n");
	if (key == e->expose)
		printf("expose");
	if (key == e->close)
		exit(EXIT_FAILURE);
	return (0);
}

int main(void)
{
	t_env	*e;

	e = init_e();
	int y = 100;
	if ((e->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((e->mlx_win = mlx_new_window(e->mlx_ptr, e->w_screen, e->h_screen, "Phileap")) == NULL)
		return (EXIT_FAILURE);
	while (y < 300)
		mlx_pixel_put(e->mlx_ptr, e->mlx_win, 200, y++, 0xFFFFFF);
	mlx_key_hook(e->mlx_win, handle_key, e);
	mlx_loop(e->mlx_ptr);
	return (EXIT_SUCCESS);
}