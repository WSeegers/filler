/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 04:19:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:03:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "filler.h"
#include "f_memory.h"

void init_game(t_info **info_ptr)
{
	t_info *info;

	*info_ptr = (t_info*)f_memalloc(sizeof(**info_ptr));
	info = *info_ptr;
	info->m_tok = 0;
	info->o_tok = 0;
	info->m_height = 0;
	info->m_width = 0;
	info->map = NULL;
	info->t_height = 0;
	info->t_width = 0;
	info->token = NULL;
	info->m_max_h = 0;
	info->m_min_h = INT_MAX;
	info->m_max_w = 0;
	info->m_min_w = INT_MAX;
	info->o_max_h = 0;
	info->o_min_h = INT_MAX;
	info->o_max_w = 0;
	info->o_min_w = INT_MAX;
	info->token_row = INT_MAX;
	info->token_col = INT_MAX;
}
