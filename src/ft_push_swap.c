/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:07:24 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/01 17:10:04 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"


void	printlist(t_pile *node)
{
	if (node == NULL)
		return ;
	printf("%d\n", node->num);
	printlist(node->next);
}


void	ft_free(t_pile *data)
{
	t_pile	*current;
	t_pile	*next;

	current = data;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	main(int argc, char *argv[])
{
	t_pile	*lst;
	int	i;

	i = 0;
	lst = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			while (argv[i])
				i++;
		}
		if (!ft_test_param(argv))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (argc == 2)
			make_stack_one(&lst, argv, i - 1);
		else
			make_stack(&lst, argv, argc - 1);
		if (is_sort(&lst))
			return (0);
		if (element_size(lst) == 3)
		{
			sort_3(&lst);
			return (0);
		}
		// printlist(lst);
		// printf("\n");
		get_index(&lst);
		ft_sort(&lst);
		// printlist(lst);
		ft_free(lst);
	}
	return (0);
}
