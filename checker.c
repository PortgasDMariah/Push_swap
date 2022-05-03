/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:46:12 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/27 14:47:41 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "struct.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

void	deleteallnodes2(t_node *start)
{
	t_node	*temp;

	while (start != NULL)
	{
		temp = start;
		start = start -> next;
		if (!temp)
			return ;
		free(temp);
	}
}

void	quit_properly(char *str, t_data *list, t_data *listb, int tmp)
{
	if (listb->head)
		deleteallnodes2(listb->head);
	if (tmp == 1)
	{
		free(str);
		quit_well(list, 1);
	}
	quit_well(list, 3);
}

void	apply_move(char *str, t_data *list, t_data *listb)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ft_rotate2(list, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rrotate2(list, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_swap2(list, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rotate2(listb, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrotate2(listb, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_swap2(listb, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa2(list, listb, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb2(list, listb, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr2(list, listb, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		doublerotate2(list, listb, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(list, listb, 0);
	else
		quit_properly(str, list, listb, 1);
}

void	org(char **av, int ac, t_data *list)
{
	list->tot = ac;
	if (ac <= 2)
		one_arg(list, av[1]);
	while (av[list->i] && ((ft_parsing(av[list->i], list) == 0)
			|| ft_parsing((av[list->i]), list)))
	{
		list->val = ft_parsing(av[list->i], list);
		list->j = (list->i) + 1;
		while (av[list->j])
		{
			if (list->val == ft_parsing((av[(list->j)++]), list))
			{
				quit_well(list, 1);
			}
		}
		create_stack_a(list, av[list->i], list->i);
		(list->i)++;
	}
}

int	main(int ac, char **av)
{
	t_data	stack_a;
	t_data	stack_b;
	char	*line;

	line = "bonjour";
	init(&stack_a, &stack_b);
	org(av, ac, &stack_a);
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL || (ft_num(line[0]) == 1))
			break ;
		apply_move(line, &stack_a, &stack_b);
		free(line);
	}
	if (sorted_or_not(&stack_a) == 0 || stack_b.head)
		ft_printf("KO\n");
	else if (!stack_b.head)
		ft_printf("OK\n");
	quit_properly("", &stack_a, &stack_b, 0);
	return (0);
}
