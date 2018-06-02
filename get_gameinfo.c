/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gameinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:03:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 04:46:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "f_print.h"
#include "f_io.h"
#include "f_string.h"
#include "f_memory.h"

static void	get_players(t_info *info)
{
	char *line;

	f_next_line(&line, STDIN);
	if (line[10] == '1')
	{
		info->m_tok = 'O';
		info->o_tok = 'X';
	}
	else
	{
		info->m_tok = 'X';
		info->o_tok = 'O';
	}
	f_strdel(&line);
}

static void get_mapsize(t_info *info)
{
	char	*line;
	char 	*nbr;

	f_next_line(&line, STDIN);
	nbr = f_strchr(line, ' ');
	info->m_height = f_atoi(nbr);
	nbr = f_strchr(nbr + 1, ' ');
	info->m_width = f_atoi(nbr);
	info->map = s_grid_create(info->m_height, info->m_width);
}

void		get_gameinfo(t_info *info_ptr)
{
	get_players(info_ptr);
	f_print_err("got players\n");
	get_mapsize(info_ptr);
}

