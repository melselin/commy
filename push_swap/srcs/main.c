/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:25:58 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/20 16:24:57 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (2 == argc)
		argv = split_string(argv[1], ' ');
	initialize_stack(&stack_a, argv + 1, 2 == argc);
	if (!check_sorted(&stack_a))
	{
		if (get_stack_size(stack_a) <= 5)
			sort_small_stack(&stack_a, &stack_b);
		else
			sort_large_stack(&stack_a, &stack_b);
	}
	free_stack_memory(&stack_a);
}

void	initialize_stack(t_list **stack_a, char **argv, bool is_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_num(argv[i]))
			handle_error(stack_a, argv, is_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			handle_error(stack_a, argv, is_argc_2);
		if (is_duplicate(*stack_a, (int)nbr))
			handle_error(stack_a, argv, is_argc_2);
		add_node_to_stack(stack_a, (int)nbr);
		++i;
	}
	if (is_argc_2)
		free_initial_memory(argv);
}

void	handle_error(t_list **stack_a, char **argv, bool is_argc_2)
{
	free_stack_memory(stack_a);
	if (is_argc_2)
		free_initial_memory(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_initial_memory(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack_memory(t_list **stack)
{
	t_list	*temp;
	t_list	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
