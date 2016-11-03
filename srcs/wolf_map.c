/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:34:48 by smassand          #+#    #+#             */
/*   Updated: 2016/11/03 10:34:51 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			set_map(t_wolf *wolf)
{
	if (wolf->map == 1)
		lvl_one(wolf);
	else if (wolf->map == 2)
		lvl_two(wolf);
	else if (wolf->map == 3)
		lvl_three(wolf);
	else if (wolf->map == 4)
		lvl_four(wolf);
	else if (wolf->map == 5)
		lvl_five(wolf);
	else
		lvl_one(wolf);
}

void			parse_map(t_wolf *wolf, int worldmap[MAPWIDTH][MAPHEIGHT])
{
	int			i;
	int			j;

	i = 0;
	while (i < MAPWIDTH)
	{
		j = 0;
		while (j < MAPHEIGHT)
		{
			wolf->worldmap[i][j] = worldmap[i][j];
			j++;
		}
		i++;
	}
}
