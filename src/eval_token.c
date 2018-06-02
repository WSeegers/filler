/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 08:14:03 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:39:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static long eval_pos(t_info *info, size_t row, size_t col)
{
	size_t	trow;
	size_t	tcol;
	long	total;
	int		invalid;
	int		map_val;
	
	trow = -1;
	total = 0;
	invalid = -1;
	while (++trow < info->t_height)
	{
		tcol = -1;
		while (++tcol < info->t_width)
		{
			map_val = s_grid_get(info->token, trow, tcol) *
						s_grid_get(info->map, row + trow, col + tcol);
			if (map_val == OP_VAL)
				return (MY_VAL);
			total += map_val;
			if ((invalid += (map_val == MY_VAL)) == 1)
				return (MY_VAL);
		}
	}
	if (!invalid)
		return (total);
	return (MY_VAL);
}

void	eval_token(t_info *info)
{
	size_t row;
	size_t col;
	long score;
	long newval;

	info->token_row = INT_MAX;
	score = MY_VAL;
	row = -1;  //can be optimised using max position
	while (++row < info->m_height - info->t_height + 1)
	{
		col = -1;
		while (++col < info->m_width - info->t_width + 1)
			if ((newval = eval_pos(info, row, col)) > score)
			{
				score = newval;
				info->token_row = row;
				info->token_col = col;
			}
	}
}
