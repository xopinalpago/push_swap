 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:46:16 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/22 11:47:06 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	push(t_pile **data1, t_pile **data2)
{
	t_pile	*tmp;
	t_pile	*element;

	if (!*data1)
		return ;
	element = (*data1)->next;
	tmp = *data1;
	tmp->next = *data2;
	*data2 = tmp;
	*data1 = element;
}

void	swap(t_pile **data)
{
	t_pile	*element;

	if (!*data || !(*data)->next)
		return ;
	element = (*data)->next;
	(*data)->next = (*data)->next->next;
	element->next = *data;
	*data = element;
}

// void	rotate(t_pile **data)
// {
// 	t_pile	*tmp;
// 	// int		first;

// 	tmp = *data;
// 	// first = tmp->num;
// 	if (!tmp || !tmp->next)
// 		return ;
	
	
// 	while (tmp->next != NULL)
// 	{
// 		tmp->num = tmp->next->num;
// 		tmp = tmp->next;
// 	}
// 	tmp->num = first;
// }

void	rotate(t_pile **data)
{
	t_pile	*current_cell;
	t_pile	*first;

	if (!data || !*data || !(*data)->next)
		return ;
	first = *data;
	*data = first->next;
	current_cell = first;
	printf("rotating %d\n", first->num);
	while (current_cell->next)
	{
		current_cell = current_cell->next;
	}
	current_cell->next = first;
	first->next = NULL;
}

void	r_rotate(t_pile **data)
{
	t_pile	*tmp;

	tmp = *data;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*data) = new_element(tmp->num, (*data));
	del_last(data);
}

void	del_last(t_pile **data)
{
	t_pile	*curr;
	t_pile	*tmp;

	curr = *data;
	tmp = NULL;
	while (curr->next != NULL)
	{
		tmp = curr;
		curr = curr->next;
	}
	free(curr);
	tmp->next = NULL;
}

