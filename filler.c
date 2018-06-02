/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:59:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 08:31:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "f_io.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include "f_io.h"
#include "f_string.h"
#include "f_print.h"
#include "f_memory.h"

void place_token(t_info *info)
{
	f_print_nbr(info->token_row);
	f_print_str(" ");
	f_print_nbr(info->token_col);
	f_print_str("\n");
}

int		main(void)
{
	t_info	*info;
	int		game_on;

	//char buf[500];
	//int		ret;

	game_on = 1;
	info = NULL;
	init_game(&info);
	while (game_on)
	{
		if (!info->m_tok)
			get_gameinfo(info);	
		else
			f_skip_line(STDIN);
		fprintf(stderr, "I am '%c' and my oponent is '%c'\n", info->m_tok, info->o_tok);
		fprintf(stderr, "The map is %lu high x %lu wide\n", info->m_height, info->m_width);
		parse_map(info);
		parse_token(info);
		fprintf(stderr, "The token is %lu high x %lu wide\n", info->t_height, info->t_width);
		eval_map(info);
		s_grid_print_fd(2, info->map);
		fprintf(stderr, "O MAX: (%lu, %lu)\tO MIN: (%lu, %lu)\n", info->o_max_w, info->o_max_h, info->o_min_w, info->o_min_h);
		fprintf(stderr, "M MAX: (%lu, %lu)\tM MIN: (%lu, %lu)\n", info->m_max_w, info->m_max_h, info->m_min_w, info->m_min_h);
		s_grid_print_fd(2, info->token);
		eval_token(info);
		place_token(info);
	}

}
