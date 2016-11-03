/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_speed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:14:45 by smassand          #+#    #+#             */
/*   Updated: 2016/11/01 20:14:48 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		wolf_speed(t_wolf *wolf, t_speed *s)
{
	speed_init(s);
	wolf->oldtime = wolf->time;
	wolf->time = SDL_GetTicks();
	s->frametime = (wolf->time - wolf->oldtime) / 1000.0;
	s->movespeed = s->frametime * 5.0;
	s->rotspeed = s->frametime * 3.0;
}

void		speed_init(t_speed *s)
{
	s->frametime = 0;
	s->movespeed = 0;
	s->rotspeed = 0;
}
