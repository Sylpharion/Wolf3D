/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:51 by smassand          #+#    #+#             */
/*   Updated: 2016/11/03 14:52:17 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		key_esc(t_wolf *wolf)
{
	SDL_DestroyWindow(wolf->window);
	SDL_Quit();
	exit(0);
}

void		key_up(t_wolf *wolf, t_speed *s)
{
	if (!wolf->worldmap[(int)(wolf->posx + wolf->dirx *
								s->movespeed)][(int)wolf->posy])
		wolf->posx += wolf->dirx * s->movespeed;
	if (!wolf->worldmap[(int)wolf->posx][(int)(wolf->posy +
								wolf->diry * s->movespeed)])
		wolf->posy += wolf->diry * s->movespeed;
}

void		key_down(t_wolf *wolf, t_speed *s)
{
	if (!wolf->worldmap[(int)(wolf->posx - wolf->dirx *
								s->movespeed)][(int)wolf->posy])
		wolf->posx -= wolf->dirx * s->movespeed;
	if (!wolf->worldmap[(int)wolf->posx][(int)(wolf->posy -
								wolf->diry * s->movespeed)])
		wolf->posy -= wolf->diry * s->movespeed;
}

void		key_left(t_wolf *wolf, t_speed *s)
{
	double olddirx;
	double oldplanex;

	olddirx = wolf->dirx;
	oldplanex = wolf->planex;
	wolf->dirx = wolf->dirx * cos(s->rotspeed) -
					wolf->diry * sin(s->rotspeed);
	wolf->diry = olddirx * sin(s->rotspeed) + wolf->diry *
					cos(s->rotspeed);
	wolf->planex = wolf->planex * cos(s->rotspeed) -
					wolf->planey * sin(s->rotspeed);
	wolf->planey = oldplanex * sin(s->rotspeed) + wolf->planey *
					cos(s->rotspeed);
}

void		key_right(t_wolf *wolf, t_speed *s)
{
	double olddirx;
	double oldplanex;

	olddirx = wolf->dirx;
	oldplanex = wolf->planex;
	wolf->dirx = wolf->dirx * cos(-s->rotspeed) -
					wolf->diry * sin(-s->rotspeed);
	wolf->diry = olddirx * sin(-s->rotspeed) + wolf->diry *
					cos(-s->rotspeed);
	wolf->planex = wolf->planex * cos(-s->rotspeed) -
					wolf->planey * sin(-s->rotspeed);
	wolf->planey = oldplanex * sin(-s->rotspeed) + wolf->planey *
					cos(-s->rotspeed);
}
