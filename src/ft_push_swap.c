/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:07:24 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/24 17:21:04 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"


void	printlist(t_pile *node)
{
	if (node == NULL)
		return ;
	printf("%d ", node->num);
	printlist(node->next);
}

t_pile	*getfirstpointer(t_pile *head)
{
	t_pile	*tmp;

	tmp = head;
	if (tmp == NULL)
	{
		printf("La liste chaînée est vide.\n");
		return (NULL);
	}
	return (tmp);
}

size_t	element_size(t_pile *lst)
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

void	ft_sort(t_pile **data1, t_pile **data2, size_t len)
{
	size_t	i;
	int		pivot;
	int		size_less;
	int		size_greater;

	if (len < 2)
		return ;
	i = 0;
	size_less = len;
	size_greater = 0;
	// pivot = (get_max(data1) + get_min(data1)) / 2;
	pivot = (*data1)->num; 
	printf("pivot = %d\n", pivot);
	printf("len = %ld\n", len);
	while (i < len)
	{
		if ((*data1)->num > pivot)
		{
			printf("test1\n");
			push(data1, data2);
			size_less--;
			size_greater++;
		}
		else
		{
			printf("test2\n");
			rotate(data1);
			// size_less++;
		}
		i++;
	}
	printf("Liste 1 : ");
	printlist(*data1);
	printf("\n");
	printf("Liste 2 : ");
	printlist(*data2);
	printf("\n");
	// printf("****************************\n");
	ft_sort(data1, data2, size_less);
	ft_sort(data2, data1, size_greater);
}


int	main(int argc, char *argv[])
{
	t_pile	*lst;
	t_pile	*lst2;
	size_t	len;

	lst = NULL;
	lst2 = NULL;
	if (argc > 1)
	{
		make_stack(&lst, argv, argc - 1);
		printf("Etape 0 :\n");
		printlist(lst);
		printf("\n");
		printf("Etape 1 :\n");
		// push(&lst, &lst2);
		// push(&lst2, &lst);
		// push(&lst, &lst2);
		len = element_size(lst);
		// printf("len = %ld\n", len);
		ft_sort(&lst, &lst2, len);
		printf("Liste 1 : ");
		printlist(lst);
		// printf("\nListe 2 : ");
		// printlist(lst2);
		// printf("\n");
		// printf("Etape 2 :\n");
		// rotate(&lst);
		// printlist(lst);
		// printf("\n");
		// r_rotate(&lst2);
		// printlist(lst2);
		// printf("\n");
	}
	return (0);
}
