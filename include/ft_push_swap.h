/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:41:45 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/01 17:14:14 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int				num;
	long			index;
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
t_pile	*new_element(int num, long index, t_pile *next);
void	make_stack(t_pile **data1, char **sdata, int size);
long	element_size(t_pile *lst);
int		get_min(t_pile **data);
int		get_max(t_pile **data);
int		is_sort(t_pile **data);
void	sort_3(t_pile **data);
void	ft_sort(t_pile **data1);
void	printlist(t_pile *node);
int		*ft_tri_array(int *dataarr, size_t len);
void	make_index(int *dataarr, size_t len, t_pile **data);
void	get_index(t_pile **data);
long	get_pos(t_pile **data1, long index);
void	make_stack_one(t_pile **data1, char **sdata, int size);
void	print_op_s(t_pile **data1, int op);
void	print_op_r(t_pile **data1, int op);
void	print_op_p(t_pile **data1, t_pile **data2, int op);

#endif