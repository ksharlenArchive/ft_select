/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:46:33 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 15:31:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

//TODO first mode second last del

static void	draw_status_line(size_t row, size_t pos,
	size_t ncols, const char *color)
{
	set_pos_cursor(pos, row);
	ft_printf("%v%s%*s", STDWORK, color,
		ncols, "");
	set_pos_cursor(pos, row);
}

void	print_info_line(t_info_args *args)
{
	size_t	shift;

	shift = 0;
	draw_status_line(args->wn.rows, 0, args->wn.cols, COLOR_LINE_STAT);
	if (args->sdm && args->sdm->status & READ_FILES)
	{
//TODO: need make defense
		draw_status_line(args->wn.rows, 0, SIZE_ROM, COLOR_R_MODE);
		ft_printf("%s", COLOR_BLACK);
		shift += ft_write(STDWORK, READ_ONLY_MODE, SIZE_ROM) + 1;
		draw_status_line(args->wn.rows, SIZE_ROM, 0, COLOR_LINE_STAT);
	}
	set_pos_cursor(shift, args->wn.rows);
	draw_status_line(args->wn.rows, shift, 0, COLOR_DFLT);
	shift += ft_write(STDWORK, DELETE_ELEM, SIZE_STR_DEL_ELEM);
	shift += ft_write(STDWORK, args->lde.name, args->lde.size_name) + 1;
	draw_status_line(args->wn.rows, 0, 0, FT_COLOR_DFLT);
}