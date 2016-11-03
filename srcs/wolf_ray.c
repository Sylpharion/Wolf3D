/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:34:50 by smassand          #+#    #+#             */
/*   Updated: 2016/11/01 19:34:56 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		wolf_get_ray(t_wolf *wolf, t_ray *ray)
{
	wolf_ray_sidedist(ray);
	while (ray->hit == 0)
		wolf_ray_loop(wolf, ray);
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapx - ray->rayposx + (1 - ray->stepx) /
							2) / ray->raydirx;
	else
		ray->perpwalldist = (ray->mapy - ray->rayposy + (1 - ray->stepy) /
							2) / ray->raydiry;
	wolf->lineheight = (int)(HEIGHT / ray->perpwalldist);
	wolf->drawstart = -wolf->lineheight / 2 + HEIGHT / 2;
	if (wolf->drawstart < 0)
		wolf->drawstart = 0;
	wolf->drawend = wolf->lineheight / 2 + HEIGHT / 2;
	if (wolf->drawend >= HEIGHT)
		wolf->drawend = HEIGHT - 1;
}

void		wolf_ray_loop(t_wolf *wolf, t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
	if (wolf->worldmap[ray->mapx][ray->mapy] > 0)
		ray->hit = 1;
}

void		wolf_ray_sidedist(t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->rayposx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->rayposx) *
							ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->rayposy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->rayposy) *
							ray->deltadisty;
	}
}
