/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:24:27 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:25:28 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (check_sorted(stack_a) || size == 0 || size == 1)
		return ;
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_three(t_list **stack_a)
{
	t_list	*head;
	int		a;
	int		b;
	int		c;

	head = *stack_a;
	a = head->value;
	b = head->next->value;
	c = head->next->next->value;
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c)
		reverse_rotate_a(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_gap(stack_a, get_min(stack_a, INT_MIN));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		reverse_rotate_a(stack_a);
	if (check_sorted(stack_a))
		return ;
	push_to_b(stack_b, stack_a);
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_gap(stack_a, get_min(stack_a, INT_MIN));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (distance == 4)
		reverse_rotate_a(stack_a);
	if (check_sorted(stack_a))
		return ;
	push_to_b(stack_b, stack_a);
	sort_four(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

int	find_gap(t_list **stack, int value)
{
	t_list	*head;
	int		distance;

	head = *stack;
	distance = 0;
	while (head)
	{
		if (head->value == value)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
