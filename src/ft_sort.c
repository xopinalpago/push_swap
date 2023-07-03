/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:41:36 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/14 10:12:12 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	sort_3(t_pile **data)
{
	t_pile	*current_cell;

	current_cell = *data;
	if (current_cell->num == get_min(data))
	{
		print_op_ra(data, 2);
		print_op_s(data, 1);
	}
	else if (current_cell->num == get_max(data))
	{
		if (current_cell->next->num == get_min(data))
			print_op_ra(data, 1);
		else
		{
			print_op_s(data, 1);
			print_op_ra(data, 2);
		}
	}
	else
	{
		if (current_cell->next->num == get_min(data))
			print_op_s(data, 1);
		else
			print_op_ra(data, 2);
	}
}

void	sort_tiny(t_pile **data1)
{
	t_pile	*data2;

	data2 = NULL;
	while (element_size(*data1) > 3)
	{
		min_up(data1);
		print_op_p(data1, &data2, 1);
	}
	if (!is_sort(data1))
		sort_3(data1);
	while (data2)
	{
		print_op_p(data1, &data2, 2);
	}
}

void	ft_pre_sort(t_pile **data1, t_pile **data2, int med)
{
	while (element_size(*data1) != 1)
	{
		if ((*data1)->num != get_max(data1))
		{
			if ((*data1)->num >= med)
			{
				print_op_p(data1, data2, 1);
				print_op_rb(data2, 1);
			}
			else
				print_op_p(data1, data2, 1);
		}
		else
			print_op_ra(data1, 2);
	}
}

void	ft_opti(t_pile **data2, t_pile **data1, int to_move_b)
{
	int		maj;
	long	pos_move;
	long	pos_move2;

	pos_move = get_current_pos(data2, to_move_b);
	maj = get_majorant(data1, to_move_b);
	pos_move2 = get_current_pos(data1, maj);
	while ((*data2)->num != to_move_b && (*data1)->num != maj)
	{
		if ((pos_move > element_size(*data2) / 2 + 1)
			&& (pos_move2 > element_size(*data1) / 2 + 1))
			print_op_rr(data1, data2, 2);
		else if ((pos_move < element_size(*data2) / 2 + 1)
			&& (pos_move2 < element_size(*data1) / 2 + 1))
			print_op_rr(data1, data2, 1);
		else
			break ;
	}
}

void	ft_put_up(t_pile **data2, t_pile **data1, int to_move_b)
{
	int		maj;
	long	pos_move;

	ft_opti(data2, data1, to_move_b);
	pos_move = get_current_pos(data2, to_move_b);
	while ((*data2)->num != to_move_b)
	{
		if (pos_move > element_size(*data2) / 2 + 1)
			print_op_rb(data2, 2);
		else
			print_op_rb(data2, 1);
	}
	maj = get_majorant(data1, to_move_b);
	pos_move = get_current_pos(data1, maj);
	while ((*data1)->num != maj)
	{
		if (pos_move > element_size(*data1) / 2 + 1)
			print_op_ra(data1, 2);
		else
			print_op_ra(data1, 1);
	}
	print_op_p(data1, data2, 2);
}
