/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:50:49 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/13 12:54:38 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	*ft_tri_array(int *dataarr, long len)
{
	int		temp;
	long	i;
	long	j;

	i = 0;
	j = 0;
	temp = 0;
	while (i < len - 1)
	{
		while (j < len - i - 1)
		{
			if (dataarr[j] > dataarr[j + 1])
			{
				temp = dataarr[j];
				dataarr[j] = dataarr[j + 1];
				dataarr[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (dataarr);
}

int	get_index(t_pile **data)
{
	long	i;
	int		*dataarr;
	int		med;
	t_pile	*curr;

	i = 0;
	curr = *data;
	dataarr = (int *) malloc(element_size(*data) * sizeof(int));
	if (!dataarr)
		return (0);
	while (i < element_size(*data))
	{
		dataarr[i] = curr->num;
		curr = curr->next;
		i++;
	}
	dataarr = ft_tri_array(dataarr, element_size(*data));
	med = dataarr[element_size(*data) / 2];
	free(dataarr);
	return (med);
}

int	get_majorant(t_pile **data1, int num)
{
	int		maj;
	t_pile	*curr;

	curr = *data1;
	maj = get_max(data1);
	while (curr)
	{
		if (curr->num > num && curr->num < maj)
			maj = curr->num;
		curr = curr->next;
	}
	return (maj);
}

void	get_cost(t_pile **data1, t_pile **data2)
{
	int		cost;
	t_pile	*curr;

	cost = 0;
	curr = *data2;
	while (curr)
	{
		if (curr->pos > element_size(*data2) / 2 + 1)
			cost = element_size(*data2) - curr->pos + 1;
		else
			cost = curr->pos - 1;
		if (curr->pos_maj > element_size(*data1) / 2 + 1)
			cost += element_size(*data1) - curr->pos_maj + 1;
		else
			cost += curr->pos_maj - 1;
		curr->cost = cost;
		curr = curr->next;
	}
}

void	min_up(t_pile **data1)
{
	long	min_pos;

	min_pos = get_current_pos(data1, get_min(data1));
	if (min_pos > element_size(*data1) / 2 + 1)
		while ((*data1)->num != get_min(data1))
			print_op_ra(data1, 2);
	else
		while ((*data1)->num != get_min(data1))
			print_op_ra(data1, 1);
}
