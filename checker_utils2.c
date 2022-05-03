/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:19:31 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/27 13:02:26 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	ss(t_data *list, t_data *listb, int tmp)
{
	if (tmp == 1)
		ft_printf("ss\n");
	if (list->head || list->head->next != NULL)
		ft_swap2(list, 0);
	if (listb->head || list->head->next != NULL)
		ft_swap2(listb, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_swap2(t_data *list, int m)
{
	t_node	*tmp;

	if (m == 1)
		ft_printf("sa\n");
	else if (m == 2)
		ft_printf("sb\n");
	if (!list->head || !list->head->next)
		return ;
	tmp = list->head;
	tmp->prev = tmp->next;
	if (!tmp->next->next)
		tmp->next = NULL;
	else
		tmp->next = tmp->next->next;
	tmp = tmp->prev;
	tmp->next = tmp->prev;
	tmp->prev = NULL;
	list->head = tmp;
}

void	ft_rrotate2(t_data *list, int m)
{
	if (!list->head)
	{
		return ;
	}
	if (m == 1)
		ft_printf("rra\n");
	else if (m == 2)
		ft_printf("rrb\n");
	if (!list->head->next)
		return ;
	if (ft_lstsize(list->head) == 2)
	{
		ft_swap2(list, 0);
		return ;
	}
	list->before = list->last->prev;
	list->before->next = NULL;
	list->last->prev = NULL;
	list->last->next = list->head;
	list->head->prev = list->last;
	list->head = list->head->prev;
	list->last = list->before;
	list->before = list->before->prev;
}

void	ft_rotate2(t_data*list, int m)
{
	t_node	*tmp;
	t_node	*node;

	if (!list->head)
		return ;
	if (m == 1)
		ft_printf("ra\n");
	else if (m == 2)
		ft_printf("rb\n");
	node = list->head;
	tmp = list->head;
	if (node->next == NULL)
	{
		tmp->prev = node;
		node->next = tmp;
		list->last = node->next;
		list->head = node;
		return ;
	}
	node = node->next;
	node->prev = NULL;
	tmp->next = NULL;
	list->head = node;
	rotate_continu(tmp, node, list);
}
