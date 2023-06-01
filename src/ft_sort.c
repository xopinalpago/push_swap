/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:41:36 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/01 17:13:26 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	sort_3(t_pile **data)
{
	t_pile	*current_cell;

	current_cell = *data;
	if (current_cell->num == get_min(data))
	{
		print_op_r(data, 2);
		print_op_s(data, 1);
	}
	else if (current_cell->num == get_max(data))
	{
		if (current_cell->next->num == get_min(data))
			print_op_r(data, 1);
		else
		{
			print_op_s(data, 1);
			print_op_r(data, 2);
		}
	}
	else
	{
		if (current_cell->next->num == get_min(data))
			print_op_s(data, 1);
		else
			print_op_r(data, 2);
	}
}

long	get_pos(t_pile **data1, long index)
{
	long	pos;
	t_pile	*curr;

	pos = 1;
	curr = *data1;
	while (curr->next)
	{
		if (curr->index == index)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

void	print_op_s(t_pile **data1, int op)
{
	if (op == 1)
	{
		swap(data1);
		printf("sa\n");
	}
	else if (op == 2)
	{
		swap(data1);
		printf("sb\n");
	}
}

void	print_op_r(t_pile **data1, int op)
{
	if (op == 1)
	{
		rotate(data1);
		printf("ra\n");
	}
	else if (op == 2)
	{
		r_rotate(data1);
		printf("rra\n");
	}
}

void	print_op_p(t_pile **data1, t_pile **data2, int op)
{
	if (op == 1)
	{
		push(data1, data2);
		printf("pb\n");
	}
	else if (op == 2)
	{
		push(data2, data1);
		printf("pa\n");
	}
}

void	ft_sort(t_pile **data1)
{
	long	index;
	t_pile	*data2;

	data2 = NULL;
	index = 1;
	while ((*data1)->next)
	{
		if (get_pos(data1, index) * 2 < element_size(*data1))
			while ((*data1)->index != index)
				print_op_r(data1, 1);
		else
			while ((*data1)->index != index)
				print_op_r(data1, 2);
		// printlist(*data1);
		// printf("\n");
		if ((*data1)->index == index)
			print_op_p(data1, &data2, 1);
		index++;
	}
	while (data2)
		print_op_p(data1, &data2, 2);
}
