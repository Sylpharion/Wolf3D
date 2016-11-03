/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:09:01 by smassand          #+#    #+#             */
/*   Updated: 2016/11/01 20:09:03 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		drawback(t_wolf *wolf)
{
	wolf->background = IMG_Load("./pictures/poke.png");
	if (!wolf->background)
		draw_basic(wolf);
	else
	{
		wolf->texture = SDL_CreateTextureFromSurface(wolf->renderer,
													wolf->background);
		wolf->dest.x = 0;
		wolf->dest.y = 0;
		wolf->dest.w = WIDTH;
		wolf->dest.h = HEIGHT;
		SDL_RenderCopy(wolf->renderer, wolf->texture, NULL, &wolf->dest);
	}
}

void		draw_basic(t_wolf *wolf)
{
	int x;
	int y;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			if (y <= HEIGHT / 2)
				SDL_SetRenderDrawColor(wolf->renderer, 0, 255, 255, 0);
			else
				SDL_SetRenderDrawColor(wolf->renderer, 150, 150, 0, 0);
			SDL_RenderDrawPoint(wolf->renderer, x, y);
			y++;
		}
		x++;
	}
}

void		draw_map(t_wolf *wolf, t_ray *ray, t_color *c)
{
	color_init(c);
	if (wolf->posy < ray->mapy && wolf->posx < ray->mapx)
		c->r = 150;
	if (wolf->posy > ray->mapy && wolf->posx > ray->mapx)
		c->g = 150;
	if (wolf->posy < ray->mapy && wolf->posx > ray->mapx)
		c->b = 150;
	if (wolf->posy > ray->mapy && wolf->posx < ray->mapx)
	{
		c->g = 150;
		c->r = 150;
	}
	if (ray->side == 1)
	{
		c->r /= 3;
		c->g /= 3;
		c->b /= 3;
	}
	if (wolf->worldmap[ray->mapx][ray->mapy] == 5)
	{
		c->r = 255;
		c->b = 255;
	}
	ft_draw(wolf, c);
}

void		ft_draw(t_wolf *wolf, t_color *c)
{
	SDL_SetRenderDrawColor(wolf->renderer, c->r, c->g, c->b, 0);
	while (wolf->drawstart < wolf->drawend)
	{
		SDL_RenderDrawPoint(wolf->renderer, wolf->x, wolf->drawend);
		wolf->drawend--;
	}
}
