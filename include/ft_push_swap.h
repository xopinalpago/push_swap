/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:41:45 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/22 11:33:17 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int				num;
	struct s_pile	*next;
}	t_pile;

int		ft_digit(char **data);
int		ft_doublon(char **data);
int		ft_lim_int(char **data);
int		ft_test_param(char **data);
void	push(t_pile **data1, t_pile **data2);
void	swap(t_pile **data);
void	rotate(t_pile **data);
void	del_last(t_pile **data);
void	r_rotate(t_pile **data);
t_pile	*new_element(int num, t_pile *next);
void	make_stack(t_pile **data1, char **sdata, int size);

#endif