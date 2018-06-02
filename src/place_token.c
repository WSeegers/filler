/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 09:44:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/02 09:47:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "filler.h"
#include "f_print.h"

void	place_token(t_info *info)
{
	if (info->token_row < INT_MAX)
	{
		f_print_nbr(info->token_row);
		f_print_str(" ");
		f_print_nbr(info->token_col);
	}
	else
		f_print_str("0 0");
	f_print_str("\n");
}
