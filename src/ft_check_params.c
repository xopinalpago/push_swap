/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:47:07 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/13 17:03:49 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_test_num(char **data, int i, int j)
{
	if ((j != 0) && (data[i][j] < '0' || data[i][j] > '9'))
		return (0);
	if (data[i][j] == '-' && (data[i][j + 1] <= '0' ||
		data[i][j + 1] > '9'))
		return (0);
	if (j == 0)
		if (data[i][j] == '0' && data[i][j + 1] >= '0' &&
		data[i][j + 1] <= '9')
			return (0);
	if (data[i][j] < '-' || (data[i][j] > '-' &&
		data[i][j] < '0') || data[i][j] > '9')
		return (0);
	return (1);
}

int	ft_digit(char **data, int argc)
{
	int		i;
	int		j;

	i = 1;
	if (argc == 2)
		i = 0;
	j = 0;
	while (data[i])
	{
		while (data[i][j])
		{
			if (!ft_test_num(data, i, j))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_doublon(char **data, int argc)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	j = 1;
	while (data[i])
	{
		j = i + 1;
		while (data[j])
		{
			if (ft_atoi(data[i]) == ft_atoi(data[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_lim_int(char **data, int argc)
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (data[i])
	{
		if (ft_atoi(data[i]) < -2147483648 || ft_atoi(data[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_test_param(char **data, int argc)
{
	if (!ft_digit(data, argc))
		return (0);
	if (!ft_doublon(data, argc))
		return (0);
	if (!ft_lim_int(data, argc))
		return (0);
	return (1);
}
