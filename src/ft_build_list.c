/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:47:25 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/22 11:47:35 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_pile	*new_element(int num, t_pile *next)
{
	t_pile	*element;

	element = malloc(sizeof(t_pile));
	if (!element)
		return (NULL);
	element->num = num;
	element->next = next;
	return (element);
}

void	make_stack(t_pile **data1, char **sdata, int size)
{
	while (size > 0)
	{
		*data1 = new_element(ft_atoi(sdata[size]), *data1);
		size--;
	}
}
