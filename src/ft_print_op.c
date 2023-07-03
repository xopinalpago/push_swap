/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:02:06 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/14 09:59:21 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	print_op_s(t_pile **data1, int op)
{
	if (op == 1)
	{
		swap(data1);
		write(1, "sa\n", 3);
	}
	else if (op == 2)
	{
		swap(data1);
		write(1, "sb\n", 3);
	}
}

void	print_op_ra(t_pile **data1, int op)
{
	if (op == 1)
	{
		rotate(data1);
		write(1, "ra\n", 3);
	}
	else if (op == 2)
	{
		r_rotate(data1);
		write(1, "rra\n", 4);
	}
}

void	print_op_rb(t_pile **data1, int op)
{
	if (op == 1)
	{
		rotate(data1);
		write(1, "rb\n", 3);
	}
	else if (op == 2)
	{
		r_rotate(data1);
		write(1, "rrb\n", 4);
	}
}

void	print_op_rr(t_pile **data1, t_pile **data2, int op)
{
	if (op == 1)
	{
		rotate(data1);
		rotate(data2);
		write(1, "rr\n", 3);
	}
	else if (op == 2)
	{
		r_rotate(data1);
		r_rotate(data2);
		write(1, "rrr\n", 4);
	}
}

void	print_op_p(t_pile **data1, t_pile **data2, int op)
{
	if (op == 1)
	{
		push(data1, data2);
		write(1, "pb\n", 3);
	}
	else if (op == 2)
	{
		push(data2, data1);
		write(1, "pa\n", 3);
	}
}
