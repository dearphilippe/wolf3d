/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:33:03 by passef            #+#    #+#             */
/*   Updated: 2018/02/02 18:18:52 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include "../lib/libft/libft.h"
#include "../lib/minilibx/mlx.h"
#include <math.h>
#include <string.h>
#define PI 3.14159265358979323846
#define mapWidth 10
#define mapHeight 10
#define screenWidth 1000
#define screenHeight 1000

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				w_screen;
	int				h_screen;
	int				keydown;
	char			keyup;
	int				mousedown;
	int				mouseup;
	int				mousemove;
	int				expose;
	int				close;
}					t_env;

#endif
