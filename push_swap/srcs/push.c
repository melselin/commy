/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:14 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:25:11 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_node(t_list **dest, t_list **src)
{
	t_list	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_to_b(t_list **stack_b, t_list **stack_a)
{
	push_node(stack_b, stack_a);
	write(1, "pb\n", 3);
}
