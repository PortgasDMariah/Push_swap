/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:18:28 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/27 12:56:04 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	doublerotate2(t_data*list, t_data*listb, int tmp)
{
	if (list->head)
		ft_rotate(list, 3);
	if (listb->head)
		ft_rotate(listb, 3);
	if (tmp == 1)
		ft_printf("rr\n");
}

void	rrr2(t_data*list, t_data*listb, int tmp)
{
	if (list->head)
		ft_rrotate2(list, 3);
	if (listb->head)
		ft_rrotate2(listb, 3);
	if (tmp == 1)
		ft_printf("rrr\n");
}

void	pa2(t_data*list, t_data*listb, int tmp)
{
	if (listb->head)
		pb(listb, list, 2);
	if (tmp == 1)
		ft_printf("pa\n");
}

void	pb2(t_data *list, t_data *listb, int m)
{
	int	tmp;

	if (!list->head)
		return ;
	tmp = list->head->data;
	ft_delete(list);
	if (listb->head != NULL)
		front(listb, ft_lstnew(tmp));
	else
	{
		listb->head = ft_lstnew(tmp);
		listb->head->prev = NULL;
	}
	if (m == 1)
		ft_printf("pb\n");
}
