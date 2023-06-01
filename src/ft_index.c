/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:50:49 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/01 15:20:00 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	*ft_tri_array(int *dataarr, size_t len)
{
	int		temp;
	size_t	i;
	size_t	j;

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

void	make_index(int *dataarr, size_t len, t_pile **data)
{
	size_t	i;
	long	index;
	t_pile	*curr;

	curr = *data;
	i = 0;
	index = 1;
	while (i < len)
	{
		curr = *data;
		while (curr != NULL)
		{
			if (curr->num == dataarr[i])
			{
				curr->index = index++;
				break ;
			}
			curr = curr->next;
		}
		i++;
	}
}

void	get_index(t_pile **data)
{
	long	i;
	int		*dataarr;
	t_pile	*curr;

	i = 0;
	curr = *data;
	dataarr = (int *) malloc(element_size(*data) * sizeof(int));
	if (!dataarr)
		return ;
	while (i < element_size(*data))
	{
		dataarr[i] = curr->num;
		curr = curr->next;
		i++;
	}
	dataarr = ft_tri_array(dataarr, element_size(*data));
	make_index(dataarr, element_size(*data), data);
	free(dataarr);
}
