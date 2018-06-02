/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:59:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 10:35:06 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "f_io.h"

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
			return (0);
		parse_token(info);
		eval_map(info);
		eval_token(info);
		place_token(info);
	}
}
