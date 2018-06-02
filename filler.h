/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:04:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:48:15 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stddef.h>
# include "s_grid.h"

# define MY_VAL (-999)
# define OP_VAL (999)

typedef struct	s_info
{
	char 		m_tok;
	char		o_tok;
	size_t 		m_height;
	size_t		m_width;
	t_grid		*map;
	size_t		t_height;
	size_t		t_width;
	t_grid		*token;
	t_grid		*t_token;
	size_t		m_max_h;
	size_t		m_min_h;
	size_t		m_max_w;
	size_t		m_min_w;
	size_t		o_max_h;
	size_t		o_min_h;
	size_t		o_max_w;
	size_t		o_min_w;
	size_t		token_row;
	size_t		token_col;
}				t_info;

void		init_game(t_info **info);
void		get_gameinfo(t_info *info);
int			parse_map(t_info *info);
void		parse_token(t_info *info);
void 		eval_map(t_info *info);
void		eval_token(t_info *info);
void		place_token(t_info *info);


#endif
