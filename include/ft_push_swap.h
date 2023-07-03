/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:41:45 by rmeriau           #+#    #+#             */
/*   Updated: 2023/06/13 17:08:48 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int				num;
	long			pos;
	long			pos_maj;
	long			cost;
	struct s_pile	*next;
}	t_pile;

int		ft_digit(char **data, int argc);
int		ft_doublon(char **data, int argc);
int		ft_lim_int(char **data, int argc);
int		ft_test_param(char **data, int argc);
int		ft_test_num(char **data, int i, int j);

void	push(t_pile **data1, t_pile **data2);
void	swap(t_pile **data);
void	rotate(t_pile **data);
void	del_last(t_pile **data);
void	r_rotate(t_pile **data);

t_pile	*new_element(int num, long pos, t_pile *next);
long	element_size(t_pile *lst);
int		is_sort(t_pile **data);
int		*ft_tri_array(int *dataarr, long len);
void	sort_type(t_pile *lst, int argc, char *argv[], int i);

void	get_cost(t_pile **data1, t_pile **data2);
void	get_pos_majorant(t_pile **data1, t_pile **data2);
int		get_max(t_pile **data);
int		get_min(t_pile **data);
int		get_min_cost(t_pile **data);
int		get_index(t_pile **data);
int		get_majorant(t_pile **data1, int num);
int		get_to_move(t_pile **data, long min_cost);
long	get_current_pos(t_pile **data1, long num);

void	print_op_s(t_pile **data1, int op);
void	print_op_ra(t_pile **data1, int op);
void	print_op_rb(t_pile **data1, int op);
void	print_op_p(t_pile **data1, t_pile **data2, int op);
void	print_op_rr(t_pile **data1, t_pile **data2, int op);

void	fill_current_pos(t_pile **data);
void	make_stack(t_pile **data1, char **sdata, int size);
void	ft_put_up(t_pile **data2, t_pile **data1, int to_move_b);
void	sort_3(t_pile **data);
void	sort_tiny(t_pile **data1);
void	ft_sort(t_pile **data1);
void	ft_pre_sort(t_pile **data1, t_pile **data2, int med);
void	make_stack_one(t_pile **data1, char **sdata, int size);
void	min_up(t_pile **data1);
void	ft_opti(t_pile **data2, t_pile **data1, int to_move_b);
void	ft_free(t_pile *data);
void	ft_free_str(char **str);

void	printlist(t_pile *node);

#endif