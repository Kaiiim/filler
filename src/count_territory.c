/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_territory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <kkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:43:48 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/09 17:49:18 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"

int			count_territory_enemy(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (s->enemy.t_map[y][x] == nb)
	{
		count += count_t_y_enemy(s, y, x, nb);
		count += count_t_x_enemy(s, y, x, nb);
	}
	return (count);
}

int			count_t_y_me(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (y - 1 >= 0 && s->me.t_map[y - 1][x] == 0
			&& s->m.map[y - 1][x] != s->enemy.p_char)
	{
		s->me.t_map[y - 1][x] = nb - 1;
		count++;
	}
	if (y + 1 < s->m.y_map && s->me.t_map[y + 1][x] == 0
			&& s->m.map[y + 1][x] != s->enemy.p_char)
	{
		s->me.t_map[y + 1][x] = nb - 1;
		count++;
	}
	return (count);
}

int			count_t_x_me(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (x - 1 >= 0 && s->me.t_map[y][x - 1] == 0
			&& s->m.map[y][x - 1] != s->enemy.p_char)
	{
		s->me.t_map[y][x - 1] = nb - 1;
		count++;
	}
	if (x + 1 < s->m.y_map && s->me.t_map[y][x + 1] == 0
			&& s->m.map[y][x + 1] != s->enemy.p_char)
	{
		s->me.t_map[y][x + 1] = nb - 1;
		count++;
	}
	return (count);
}

int			count_t_y_enemy(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (y - 1 >= 0 && s->enemy.t_map[y - 1][x] == 0
			&& s->m.map[y - 1][x] != s->me.p_char)
	{
		s->enemy.t_map[y - 1][x] = nb - 1;
		count++;
	}
	if (y + 1 < s->m.y_map && s->enemy.t_map[y + 1][x] == 0
			&& s->m.map[y + 1][x] != s->me.p_char)
	{
		s->enemy.t_map[y + 1][x] = nb - 1;
		count++;
	}
	return (count);
}

int			count_t_x_enemy(t_struct *s, int y, int x, int nb)
{
	int		count;

	count = 0;
	if (x - 1 >= 0 && s->enemy.t_map[y][x - 1] == 0
			&& s->m.map[y][x - 1] != s->me.p_char)
	{
		s->enemy.t_map[y][x - 1] = nb - 1;
		count++;
	}
	if (x + 1 < s->m.y_map && s->enemy.t_map[y][x + 1] == 0
			&& s->m.map[y][x + 1] != s->me.p_char)
	{
		s->enemy.t_map[y][x + 1] = nb - 1;
		count++;
	}
	return (count);
}
