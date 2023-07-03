/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:57:27 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/14 10:11:24 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

long	get_current_pos(t_pile **data1, long num)
{
	long	pos;
	t_pile	*curr;

	pos = 1;
	curr = *data1;
	while (curr->next)
	{
		if (curr->num == num)
			break ;
		pos++;
		curr = curr->next;
	}
	return (pos);
}

void	fill_current_pos(t_pile **data)
{
	t_pile	*curr;
	long	pos;

	curr = *data;
	pos = 1;
	while (curr)
	{
		curr->pos = pos;
		curr = curr->next;
		pos++;
	}
}

void	get_pos_majorant(t_pile **data1, t_pile **data2)
{
	t_pile	*curr;

	curr = *data2;
	while (curr)
	{
		curr->pos_maj = get_current_pos(data1, get_majorant(data1, curr->num));
		curr = curr->next;
	}
}

int	get_to_move(t_pile **data, long min_cost)
{
	t_pile	*tmp;

	tmp = *data;
	while (tmp != NULL)
	{
		if (tmp->cost == min_cost)
			return (tmp->num);
		tmp = tmp->next;
	}
	return (0);
}
