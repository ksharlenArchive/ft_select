/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:02:04 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/25 20:11:55 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	draw_status_line(size_t row, size_t pos,
	size_t ncols, const char *color)
{
	set_pos_cursor(pos, row);
	ft_printf("%v%s%*s", STDWORK, color,
		ncols, "");
	set_pos_cursor(pos, row);
}

void	print_small_window(t_info_args *args)
{
	size_t	center;

	center = (args->wn.cols / 2) - (SIZE_LITTLE_WIN / 2);
	set_pos_cursor(0, 0);
	ft_print_nsym(STDWORK, ' ', args->wn.cols * args->wn.rows);
	set_pos_cursor(center, args->wn.rows / 2);
	write(STDWORK, LITTLE_WIN, SIZE_LITTLE_WIN);
}

static void		draw_search_mode(t_info_args *args, size_t *shift)
{
	set_pos_cursor(*(shift + 1), args->wn.rows);
	write(STDWORK, STR_SEARCH_MODE, SIZE_SEARCH_MODE);
}

static size_t	draw_r_only_mode(t_info_args *args)
{
	size_t	shift;

	draw_status_line(args->wn.rows, 0, SIZE_ROM, COLOR_R_MODE);
	ft_printf("%s", COLOR_BLACK);
	shift = ft_write(STDWORK, READ_ONLY_MODE, SIZE_ROM) + 1;
	draw_status_line(args->wn.rows, SIZE_ROM, 0, COLOR_LINE_STAT);
	return (shift);
}

void	print_info_line(t_info_args *args)
{
	size_t	shift;

	shift = 0;
	draw_status_line(args->wn.rows, 0, args->wn.cols, COLOR_LINE_STAT);
	if (args->sdm && args->sdm->status & READ_FILES)
		shift += draw_r_only_mode(args);
	set_pos_cursor(shift, args->wn.rows);
	draw_status_line(args->wn.rows, shift, 0, COLOR_DFLT);
	shift += ft_write(STDWORK, DELETE_ELEM, SIZE_STR_DEL_ELEM);
	shift += ft_write(STDWORK, args->lde.name, args->lde.size_name) + 1;
	if (args->status & SEARCH_MODE)
		draw_search_mode(args, &shift);
	draw_status_line(args->wn.rows, 0, 0, FT_COLOR_DFLT);
	//TODO: here will search_mode
}