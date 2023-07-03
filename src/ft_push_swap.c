/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:07:24 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/14 10:12:24 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ft_sort(t_pile **data1)
{
	t_pile	*data2;
	int		min_cost;
	long	to_move_b;

	data2 = NULL;
	ft_pre_sort(data1, &data2, get_index(data1));
	while (data2)
	{
		fill_current_pos(data1);
		fill_current_pos(&data2);
		get_pos_majorant(data1, &data2);
		get_cost(data1, &data2);
		min_cost = get_min_cost(&data2);
		to_move_b = get_to_move(&data2, min_cost);
		ft_put_up(&data2, data1, to_move_b);
	}
	min_up(data1);
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

void	sort_type(t_pile *lst, int argc, char *argv[], int i)
{
	if (argc == 2)
		make_stack_one(&lst, argv, i - 1);
	else
		make_stack(&lst, argv, argc - 1);
	if (is_sort(&lst))
	{
		ft_free(lst);
		if (argc == 2)
			ft_free_str(argv);
		return ;
	}
	if (element_size(lst) <= 10)
		sort_tiny(&lst);
	else
		ft_sort(&lst);
	ft_free(lst);
	if (argc == 2)
		ft_free_str(argv);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	main(int argc, char *argv[])
{
	t_pile	*lst;
	int		i;

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
		if (!ft_test_param(argv, argc))
		{
			if (argc == 2)
				ft_free_str(argv);
			write(2, "Error\n", 6);
			return (0);
		}
		sort_type(lst, argc, argv, i);
	}
	return (0);
}
