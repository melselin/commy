/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:30 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:25:33 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cheapest_node(t_list *stack_b)
{
	long	best_match_value;
	t_list	*best_match_node;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_cost < best_match_value)
		{
			best_match_value = stack_b->push_cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match_node->cheapest = true;
}

void	complete_rotation(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

t_list	*get_cheapest_node(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*find_smallest_value(t_list *stack)
{
	long	smallest;
	t_list	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	move_nodes_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_stacks(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both_stacks(stack_a, stack_b, cheapest_node);
	complete_rotation(stack_b, cheapest_node, 'b');
	complete_rotation(stack_a, cheapest_node->target_node, 'a');
	push_to_a(stack_a, stack_b);
}
