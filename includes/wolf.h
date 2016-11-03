/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 11:08:34 by smassand          #+#    #+#             */
/*   Updated: 2016/11/02 17:36:24 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include <math.h>
# include <SDL.h>
# include <SDL_image.h>

# define MAPWIDTH 	40
# define MAPHEIGHT 	40
# define HEIGHT 	384
# define WIDTH 		512

typedef struct		s_wolf
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	SDL_Surface		*background;
	SDL_Rect		dest;
	SDL_Texture		*texture;
	int				worldmap[MAPWIDTH][MAPHEIGHT];
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				x;
	int				map;
}					t_wolf;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_speed
{
	double			frametime;
	double			movespeed;
	double			rotspeed;
}					t_speed;

typedef struct		s_ray
{
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
}					t_ray;

void				drawback(t_wolf *wolf);
void				draw_basic(t_wolf *wolf);
void				ft_draw(t_wolf *wolf, t_color *c);
void				ft_wolf(t_wolf *wolf, t_color *c, t_speed *s);
void				wolf_event(t_wolf *wolf, t_speed *s, t_color *c,
								t_ray *ray);
void				wolf_key_press(t_wolf *wolf, t_speed *s, t_color *c,
									t_ray *ray);
void				wolf_key_press_deux(t_wolf *wolf, t_color *c, t_ray *ray);
void				key_esc(t_wolf *wolf);
void				key_up(t_wolf *wolf, t_speed *s);
void				key_down(t_wolf *wolf, t_speed *s);
void				key_left(t_wolf *wolf, t_speed *s);
void				key_right(t_wolf *wolf, t_speed *s);
void				draw_map(t_wolf *wolf, t_ray *ray, t_color *c);
void				wolf_init(t_wolf *wolf, t_color *c);
void				color_init(t_color *c);
void				wolf_menu(void);
void				wolf_loop(t_wolf *wolf, t_color *c, t_speed *s);
void				wolf_speed(t_wolf *wolf, t_speed *s);
void				speed_init(t_speed *s);
void				wolf_ray_init(t_wolf *wolf, t_ray *ray);
void				wolf_get_ray(t_wolf *wolf, t_ray *ray);
void				wolf_ray_sidedist(t_ray *ray);
void				wolf_ray_loop(t_wolf *wolf, t_ray *ray);
void				set_map(t_wolf *wolf);
void				lvl_one(t_wolf *wolf);
void				lvl_two(t_wolf *wolf);
void				lvl_three(t_wolf *wolf);
void				lvl_four(t_wolf *wolf);
void				lvl_five(t_wolf *wolf);
void				parse_map(t_wolf *wolf, int worldmap[MAPWIDTH][MAPHEIGHT]);
void				wolf_error(void);

#endif
