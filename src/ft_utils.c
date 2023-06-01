/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:37:55 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/01 15:19:37 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

long	element_size(t_pile *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	get_min(t_pile **data)
{
	t_pile	*tmp;
	int		min;

	tmp = *data;
	min = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_pile **data)
{
	t_pile	*tmp;
	int		max;

	tmp = *data;
	max = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sort(t_pile **data)
{
	t_pile	*current_cell;

	if (!data || !*data || !(*data)->next)
		return (1);
	current_cell = *data;
	while (current_cell->next)
	{
		if (current_cell->num > current_cell->next->num)
			return (0);
		current_cell = current_cell->next;
	}
	return (1);
}