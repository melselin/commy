/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:32 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 18:16:23 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **stack_a)
{
	swap_nodes(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap_nodes(stack_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
}

void	swap_nodes(t_list **head)
{
	int	len;

	len = get_stack_size(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
