/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:33:03 by passef            #+#    #+#             */
/*   Updated: 2018/01/30 17:26:02 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
#define WOLF3D_H

#include "../lib/libft/libft.h"
#include "../lib/minilibx/mlx.h"
#include <math.h>
#include "../lib/sdl2/include/SDL2/SDL.h"
// #include "../lib/sdl2/include/SDL2/SDL_opengl.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

#endif
