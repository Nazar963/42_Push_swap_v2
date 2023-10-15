/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:14:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 18:36:25 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **stack_a, int print)
{
	t_list	*temp_a;
	t_list	*next_node;

	if (ft_lstsize(*stack_a) < 2)
		return ;
	temp_a = *stack_a;
	next_node = (*stack_a)->next;
	*stack_a = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, temp_a);
	ft_lstadd_front(stack_a, next_node);
	if (print != 1)
		ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(t_list **stack_b, int print)
{
	t_list	*temp_b;
	t_list	*next_node;

	if (ft_lstsize(*stack_b) < 2)
		return ;
	temp_b = *stack_b;
	next_node = (*stack_b)->next;
	*stack_b = (*stack_b)->next->next;
	ft_lstadd_front(stack_b, temp_b);
	ft_lstadd_front(stack_b, next_node);
	if (print != 1)
		ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap_a(stack_a, 1);
	ft_swap_b(stack_b, 1);
	ft_putstr_fd("ss\n", 1);
}
