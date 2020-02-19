/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:13:13 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/19 21:48:49 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			wputchar(int c)
{
	write(STDWORK, &c, 1);
	return (c);
}

void	print_args(t_info_args *args)
{
	struct s_arg	*current;
	size_t			sym_qt_in_line;

	if (args->size)
	{
		sym_qt_in_line = 0;
		write(STDWORK, "\x1b[H", 3);
		// sl_tputs(args->clear_win, 1, wputchar);
		// write(STDWORK, "\x1b[H", 3);
		current = args->begin;
		while (current)
		{
			if (args->wn.cols < (sym_qt_in_line + args->max_len_arg + (args->wn.cols / args->max_len_arg)))
			{
				ft_putchar_fd('\n', STDWORK);
				sym_qt_in_line = 0;
			}
			ft_printf("%v%s%s%s%-*s%s ", STDWORK, current->color_text,
				current->color_bck ? current->color_bck : "",
				current == args->cur_pos ? args->italics : "",
					args->max_len_arg, current->name, FT_COLOR_DFLT);
			sym_qt_in_line += args->max_len_arg;
			current = current->next;
		}
	}
	else
		EXIT();
}
