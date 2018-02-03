/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:27:56 by passef            #+#    #+#             */
/*   Updated: 2018/02/02 13:43:23 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int worldMap[mapWidth][mapHeight] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	double posX;
	double posY;
	double h_cam;
	double h_wall;
	double angle;
	double disScreen; // should be 277
	int drawStart;
	int drawEnd;
	int lineHeight;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	int x;
	//length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;
	double norm_ray;
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	hit = 0;
	x = 0;
	posX = 2;
	posY = 2;
	h_cam = 100;
	h_wall = 200;
	angle = PI / 3;
	disScreen = 160 / tan(angle / 2);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Raycaster");
	double dirX = 0, dirY = 1;
	double planeX = 0.60, planeY = 0;
	while(x < screenWidth)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)(screenWidth) - 1; //x-coordinate in camera space
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		norm_ray = sqrt(rayDirX * rayDirX + rayDirY * rayDirY);
		rayDirX /= norm_ray;
		rayDirY /= norm_ray;
		printf("Rayx : %f\n Rayy : %f\n et voici camera : %f\n", rayDirX, rayDirY, cameraX);
		//which box of the map we're in
		mapX = (int)(posX);
		mapY = (int)(posY);
		printf("position : (%f  %f )", posX, posY);
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(h_wall / rayDirX);
		double deltaDistY = fabs(h_wall / rayDirY);
		double perpWallDist;
		printf("deltaX : %f\n deltaY : %f\n", deltaDistX, deltaDistY);
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - (double)mapX) * deltaDistX / h_wall;
		}
		else
		{
			stepX = 1;
			sideDistX = ((double)mapX + 1.0 - posX) * deltaDistX / h_wall;
		}
		if (rayDirY < 0)
		{
			stepY = 1;
			sideDistY = (posY - (double)mapY) * deltaDistY / h_wall;
		}
		else
		{
			stepY = -1;
			sideDistY = ((double)mapY + 1.0 - posY) * deltaDistY / h_wall;
		}
		printf("stepX : %d\n stepY : %d\n sideDistX : %f\n sideDistY : %f\n", stepX, stepY, sideDistX, sideDistY);
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 1;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 0;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		printf("stepX : %d\n stepY : %d\n sideDistX : %f\n sideDistY : %f\n", stepX, stepY, sideDistX, sideDistY);
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			/*perpWallDist = ((double)mapX - posX + (1 - stepX) / 2) / rayDirX);*/
			perpWallDist = ((double)mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = ((double)mapY - posY + (1 - stepY) / 2) / rayDirY;
			/*perpWallDist = ((double)mapY - posY) + (1 - stepY) / 2) / rayDirY;*/
		printf("perpWallDist icic : %f\n", (perpWallDist));
		//Calculate height of line to draw on screen
		lineHeight = (int)(h_wall / perpWallDist);
		printf("perpWallDist : %f\n", (perpWallDist));
		printf("lineHeight : %d\n", lineHeight);
		//calculate lowestl and highest pixelinlt to fill in current stripe
		drawStart = 100 - lineHeight / 2 ;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = 100 + lineHeight / 2 ;
		if(drawEnd >= h_wall)
			drawEnd = h_wall - 1;
		printf("draw start : %d\n", drawStart);
		printf("draw end : %d\n", drawEnd);
		//draw the pixels of the stripe as a vertical line
		while (drawStart <= drawEnd)
			mlx_pixel_put(mlx_ptr, win_ptr, x, drawStart++ , 0xFFFFFF);
		x++;
	}
	mlx_loop(mlx_ptr);
	return 0;
}