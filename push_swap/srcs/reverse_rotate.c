/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:18 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:25:16 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*last;
	int		len;

	len = get_stack_size(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_both_stacks(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_a != cheapest_node->target_node && *stack_b != cheapest_node)
		reverse_rotate_both(stack_a, stack_b);
	set_current_positions(*stack_a);
	set_current_positions(*stack_b);
}
