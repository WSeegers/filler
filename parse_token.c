/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 04:55:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 07:10:45 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "s_grid.h"
#include "f_io.h"
#include "f_string.h"

static void	create_token(t_info *info)
{
	char	*line;
	char	*nbr;

	f_next_line(&line, STDIN);
	nbr = f_strchr(line, ' ');
	info->t_height = f_atoi(nbr);
	nbr = f_strchr(nbr + 1, ' ');
	info->t_width = f_atoi(nbr);
	info->token = s_grid_create(info->t_height, info->t_width);
	info->t_token = s_grid_create(info->t_height, info->t_width);
	f_strdel(&line);
}

static int get_key(char k)
{
	if (k == '.')
		return (0);
	if (k == '*')
		return (1);
	return (42);
}

void	parse_token(t_info *info)
{
	size_t	col;
	size_t	row;
	char	*line;

	create_token(info);
	row = -1;
	while (++row < info->t_height)
	{
		f_next_line(&line, STDIN);
		col = -1;
		while (++col < info->t_width)
		{
			s_grid_set(info->token, get_key(line[col]), row, col);
			s_grid_set(info->token, get_key(line[col]), row, col);
		}
	}	
}
