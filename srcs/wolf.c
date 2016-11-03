/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@02.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:07:20 by smassand          #+#    #+#             */
/*   Updated: 2016/10/28 10:12:39 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				main(void)
{
	t_wolf		wolf;
	t_color		c;
	t_speed		s;

	wolf_error();
	wolf_menu();
	set_map(&wolf);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return (-1);
	}
	else
		ft_wolf(&wolf, &c, &s);
	return (0);
}

void			wolf_error(void)
{
	if (MAPWIDTH < 20 || MAPHEIGHT < 20)
	{
		ft_putrainbow("FATAL ERROR : Please, don't touch my header... :(\n",
																		RED);
		exit(-1);
	}
}

void			ft_wolf(t_wolf *wolf, t_color *c, t_speed *s)
{
	wolf_init(wolf, c);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_OPENGL,
									&wolf->window, &wolf->renderer);
	while (2048)
		wolf_loop(wolf, c, s);
}

void			wolf_loop(t_wolf *wolf, t_color *c, t_speed *s)
{
	t_ray		ray;

	SDL_RenderClear(wolf->renderer);
	drawback(wolf);
	wolf->x = 0;
	while (wolf->x < WIDTH)
	{
		wolf_ray_init(wolf, &ray);
		wolf_get_ray(wolf, &ray);
		draw_map(wolf, &ray, c);
		wolf->x++;
	}
	wolf_speed(wolf, s);
	wolf_event(wolf, s, c, &ray);
	SDL_SetRenderDrawColor(wolf->renderer, 0, 0, 0, 0);
	SDL_RenderPresent(wolf->renderer);
	SDL_FreeSurface(wolf->background);
}

void			wolf_menu(void)
{
	ft_putendl("Help :");
	ft_putstr("\t- ");
	ft_putrainbow("Nord\n", RED);
	ft_putstr("\t- ");
	ft_putrainbow("Sud\n", GREEN);
	ft_putstr("\t- ");
	ft_putrainbow("Est\n", YELLOW);
	ft_putstr("\t- ");
	ft_putrainbow("ouest\n\n", BLUE);
	ft_putendl("Changer de map :");
	ft_putrainbow("\t- [1], [2], [3], [4], [5]\n", PURPLE);
	ft_putendl("Quitter :");
	ft_putrainbow("\t- [esc]\n", RED);
}
