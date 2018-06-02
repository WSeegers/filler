/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:59:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:44:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "f_io.h"
#include <limits.h>
#include "f_io.h"
#include "f_string.h"
#include "f_print.h"
#include "f_memory.h"

int		main(void)
{
	t_info	*info;

	info = NULL;
	init_game(&info);
	while (1)
	{
		if (!info->m_tok)
			get_gameinfo(info);	
		else
			f_skip_line(STDIN);
		if(parse_map(info))
		{
			f_print_str("\n");
			continue ;
		}
		parse_token(info);
		eval_map(info);
		eval_token(info);
		place_token(info);
	}
}
