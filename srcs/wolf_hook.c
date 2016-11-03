/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:52:17 by smassand          #+#    #+#             */
/*   Updated: 2016/11/01 18:52:20 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		wolf_event(t_wolf *wolf, t_speed *s, t_color *c, t_ray *ray)
{
	SDL_PollEvent(&wolf->event);
	if (wolf->event.type == SDL_KEYDOWN)
	{
		wolf_key_press(wolf, s, c, ray);
		wolf_key_press_deux(wolf, c, ray);
	}
	if (wolf->event.type == SDL_QUIT)
		key_esc(wolf);
}

void		wolf_key_press(t_wolf *wolf, t_speed *s, t_color *c, t_ray *ray)
{
	if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
										"Escape") == 0)
		key_esc(wolf);
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"Up") == 0)
		key_up(wolf, s);
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"Down") == 0)
		key_down(wolf, s);
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"Right") == 0)
		key_right(wolf, s);
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"Left") == 0)
		key_left(wolf, s);
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
										"1") == 0)
	{
		lvl_one(wolf);
		draw_map(wolf, ray, c);
	}
}

void		wolf_key_press_deux(t_wolf *wolf, t_color *c, t_ray *ray)
{
	if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"2") == 0)
	{
		lvl_two(wolf);
		draw_map(wolf, ray, c);
	}
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"3") == 0)
	{
		lvl_three(wolf);
		draw_map(wolf, ray, c);
	}
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
									"4") == 0)
	{
		lvl_four(wolf);
		draw_map(wolf, ray, c);
	}
	else if (ft_strcmp(SDL_GetKeyName(wolf->event.key.keysym.sym),
										"5") == 0)
	{
		lvl_five(wolf);
		draw_map(wolf, ray, c);
	}
}
