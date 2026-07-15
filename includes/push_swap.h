/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esttina <esttina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:41:18 by esttina           #+#    #+#             */
/*   Updated: 2026/07/16 00:50:00 by esttina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

long	ft_atol(const char *str);
int		check_validity(char *str);
int		check_duplicate(t_node *stack, int n);
void	free_stack(t_node **stack);
int		is_sorted(t_node **stack);

t_node	*ft_lstnew(int value);
void	ft_lstadd_back(t_node **stack, t_node *new_node);
int		ft_lstsize(t_node *head);

int		init_stack(t_node **stack, char **args);
void	index_stack(t_node **stack);

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	sort_3(t_node **stack);
void	sort_4_5(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);

#endif