/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:24 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:25:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		stack_size;

	stack_size = get_stack_size(*stack_a);
	while (stack_size-- > 3)
		push_to_b(stack_b, stack_a);
	sort_small_stack(stack_a, stack_b);
	while (*stack_b)
	{
		reinitialize_nodes(*stack_a, *stack_b);
		move_nodes_to_a(stack_a, stack_b);
	}
	set_current_positions(*stack_a);
	smallest = find_smallest_value(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			rotate_a(stack_a);
	else
		while (*stack_a != smallest)
			reverse_rotate_a(stack_a);
}

void	reinitialize_nodes(t_list *stack_a, t_list *stack_b)
{
	set_current_positions(stack_a);
	set_current_positions(stack_b);
	set_target_nodes(stack_a, stack_b);
	set_push_costs(stack_a, stack_b);
	set_cheapest_node(stack_b);
}

void	set_current_positions(t_list *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_nodes(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_smallest_value(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_push_costs(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_cost = len_b - (stack_b->current_position);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->current_position;
		else
			stack_b->push_cost += len_a
				- (stack_b->target_node->current_position);
		stack_b = stack_b->next;
	}
}
