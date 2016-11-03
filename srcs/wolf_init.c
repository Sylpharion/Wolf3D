/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:15:02 by smassand          #+#    #+#             */
/*   Updated: 2016/11/01 20:15:05 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		wolf_init(t_wolf *wolf, t_color *c)
{
	wolf->posx = 10.2;
	wolf->posy = 9.2;
	wolf->dirx = -1;
	wolf->diry = 0;
	wolf->planex = 0;
	wolf->planey = 0.66;
	wolf->time = 0;
	wolf->oldtime = 0;
	wolf->map = 1;
	c->r = 0;
	c->g = 0;
	c->b = 0;
}

void		color_init(t_color *c)
{
	c->r = 0;
	c->g = 0;
	c->b = 0;
}

void		wolf_ray_init(t_wolf *wolf, t_ray *ray)
{
	ray->camerax = 2 * wolf->x / (double)WIDTH - 1;
	ray->rayposx = wolf->posx;
	ray->rayposy = wolf->posy;
	ray->raydirx = wolf->dirx + wolf->planex * ray->camerax;
	ray->raydiry = wolf->diry + wolf->planey * ray->camerax;
	ray->mapx = (int)ray->rayposx;
	ray->mapy = (int)ray->rayposy;
	ray->deltadistx = sqrt(1 + (ray->raydiry * ray->raydiry) /
							(ray->raydirx * ray->raydirx));
	ray->deltadisty = sqrt(1 + (ray->raydirx * ray->raydirx) /
							(ray->raydiry * ray->raydiry));
	ray->hit = 0;
}
