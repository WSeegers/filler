/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 06:56:48 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 06:57:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "s_grid.h"

static void	check_cell(t_info *info, int val, size_t row, size_t col)
{
	int cell;

	if (row > info->m_height || 
			col > info->m_width || 
			(cell = s_grid_get(info->map, row, col)) >= val ||
			cell < 0)
		return ;
	s_grid_set(info->map, val, row, col);
}

static int check_hood(t_info *info, int val, size_t row, size_t col)
{
	if (s_grid_get(info->map, row, col) == val)
	{
		check_cell(info, val - 1, row + 1, col);
		check_cell(info, val - 1, row - 1, col);
		check_cell(info, val - 1, row, col + 1);
		check_cell(info, val - 1, row, col - 1);
		return (-1);
	}
	return (0);
}

void eval_map(t_info *info)
{
	int		done;
	int		val;
	size_t	row;
	size_t	col;

	val = OP_VAL + 1;
	while (--val)
	{
		if (done > 0)
			return ;
		done = 1;
		row = -1;
		while (++row < info->m_height)
		{
			col = -1;
			while (++col < info->m_width)
				done += check_hood(info, val, row, col);	
		}
	}
}
