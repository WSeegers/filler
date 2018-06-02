/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:03:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/06/01 01:20:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "f_io.h"
#include "f_string.h"
#include "f_print.h"

int		main(void)
{
	char buff[500];
	char *buf;
	int 	ret;


	f_next_line(&buf, STDIN);
	f_next_line(&buf, STDIN);
	f_next_line(&buf, STDIN);

	while (f_next_line(&buf, STDIN))
	{
		f_print_err(buf);
		f_print_err("\n");
	}
	f_print_err("prog end");
	return (0);
}
