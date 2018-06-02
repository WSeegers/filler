/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 02:36:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:39:21 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "filler.h"
#include "f_io.h"
#include "s_grid.h"
#include "f_math.h"

static int get_val(char k, t_info *info, size_t row, size_t col)
{
	if (k == '.')
	{
		return (s_grid_get(info->map, row, col));
	}
	if (k == info->m_tok)
	{
		info->m_max_h = f_max(info->m_max_h, row);
		info->m_min_h = f_min(info->m_min_h, row);
		info->m_max_w = f_max(info->m_max_w, col);
		info->m_min_w = f_min(info->m_min_w, col);
		return (MY_VAL);
	}
	if (k == info->o_tok)
	{
		info->o_max_h = f_max(info->o_max_h, row);
		info->o_min_h = f_min(info->o_min_h, row);
		info->o_max_w = f_max(info->o_max_w, col);
		info->o_min_w = f_min(info->o_min_w, col);
		return (OP_VAL);
	}
	return (42);
}

int		parse_map(t_info *info)
{
	size_t	row;
	size_t	col;
	char	*line;
	
	f_next_line(&line, STDIN);
	if (!f_strlen(line))
	{
		f_strdel(&line);
		return (1);
	}
	f_strdel(&line);
	row = -1;
	while (++row < info->m_height)
	{
		f_next_line(&line, STDIN);
		col = -1;
		while (++col < info->m_width)
			s_grid_set(info->map, get_val(line[4 + col], info, row, col), row, col);
	}
	f_strdel(&line);
	return (0);
}
