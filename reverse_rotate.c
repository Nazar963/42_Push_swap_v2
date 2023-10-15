/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:14:29 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_list **stack_a, int print)
{
	t_list	*temp;
	t_list	*last_node;
	int		size;

	size = ft_lstsize(*stack_a);
	temp = *stack_a;
	while (size - 2 > 0)
	{
		temp = temp->next;
		size--;
	}
	last_node = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, last_node);
	if (print != 1)
		ft_putstr_fd("rra\n", 1);
}

void	ft_reverse_rotate_b(t_list **stack_b, int print)
{
	t_list	*temp;
	t_list	*last_node;
	int		size;

	size = ft_lstsize(*stack_b);
	temp = *stack_b;
	while (size - 2 > 0)
	{
		temp = temp->next;
		size--;
	}
	last_node = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, last_node);
	if (print != 0)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate_a(stack_a, 1);
	ft_reverse_rotate_b(stack_b, 1);
	ft_putstr_fd("rrr\n", 1);
}
