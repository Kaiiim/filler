/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhalfao <kkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 17:26:54 by kkhalfao          #+#    #+#             */
/*   Updated: 2017/10/09 17:49:22 by kkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../libft/includes/libft.h"

void		check_error(t_struct *s)
{
	int		y;

	y = 0;
	while (y < s->m.y_map && !s->error)
	{
		if (ft_strlen(s->m.map[y]) != sizeof(char) * s->m.x_map)
			s->error = 2;
		y++;
	}
	if (s->error == 2)
		free_structs(s);
}
