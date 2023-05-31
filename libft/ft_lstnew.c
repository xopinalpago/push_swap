/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:39:55 by rmeriau           #+#    #+#             */
/*   Updated: 2023/05/05 14:37:25 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_temp;

	l_temp = (t_list *)malloc(sizeof(t_list));
	if (!l_temp)
		return (NULL);
	l_temp->content = content;
	l_temp->next = NULL;
	return (l_temp);
}
