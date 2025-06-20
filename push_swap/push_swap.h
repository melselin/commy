/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:30:00 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/03/22 19:30:12 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				current_position;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;
}					t_list;

// op
void				push_node(t_list **dest, t_list **src);
void				push_to_a(t_list **stack_a, t_list **stack_b);
void				push_to_b(t_list **stack_b, t_list **stack_a);

void				swap_a(t_list **stack_a);
void				swap_b(t_list **stack_b);
void				swap_both(t_list **stack_a, t_list **stack_b);
void				swap_nodes(t_list **head);

void				rotate_a(t_list **stack_a);
void				rotate_b(t_list **stack_b);
void				rotate_both(t_list **stack_a, t_list **stack_b);
void				rotate_stack(t_list **stack);
void				rotate_both_stacks(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);

void				reverse_rotate_a(t_list **stack_a);
void				reverse_rotate_b(t_list **stack_b);
void				reverse_rotate_both(t_list **stack_a, t_list **stack_b);
void				reverse_rotate_stack(t_list **stack);
void				reverse_rotate_both_stacks(t_list **stack_a,
						t_list **stack_b, t_list *cheapest_node);

// error
char				*get_next_word_in_string(char *str, char separator);
int					is_num(char *str_nbr);
char				**split_string(char *str, char separator);
int					count_words_in_string(char *str, char separator);
int					is_duplicate(t_list *stack_a, int nbr);

// main
void				initialize_stack(t_list **stack_a, char **argv,
						bool is_argc_2);
void				handle_error(t_list **stack_a, char **argv, bool is_argc_2);
void				free_stack_memory(t_list **stack);
void				free_initial_memory(char **argv);

// utils
int					get_stack_size(t_list *stack);
int					check_sorted(t_list **stack);
int					get_min(t_list **stack, int val);
t_list				*get_last_node(t_list *head);
void				add_node_to_stack(t_list **stack, int nbr);

// sort_small
void				sort_small_stack(t_list **stack_a, t_list **stack_b);
void				sort_three(t_list **stack_a);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
int					find_gap(t_list **stack, int index);

// sort_big
void				sort_large_stack(t_list **stack_a, t_list **stack_b);
void				reinitialize_nodes(t_list *stack_a, t_list *stack_b);
void				set_current_positions(t_list *stack);
void				set_target_nodes(t_list *stack_a, t_list *stack_b);
void				set_push_costs(t_list *stack_a, t_list *stack_b);

// sort_big2
void				set_cheapest_node(t_list *stack_b);
void				complete_rotation(t_list **stack, t_list *top_node,
						char stack_name);
t_list				*get_cheapest_node(t_list *stack);
t_list				*find_smallest_value(t_list *stack);
void				move_nodes_to_a(t_list **stack_a, t_list **stack_b);

#endif
