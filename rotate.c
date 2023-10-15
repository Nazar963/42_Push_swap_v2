/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:14:00 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:34 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **stack_a, int print)
{
	t_list	*first_elem;

	first_elem = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, first_elem);
	first_elem->next = NULL;
	if (print != 1)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rotate_b(t_list **stack_b, int print)
{
	t_list	*first_elem;

	first_elem = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, first_elem);
	first_elem->next = NULL;
	if (print != 1)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_a(stack_a, 1);
	ft_rotate_b(stack_b, 1);
	ft_putstr_fd("rr\n", 1);
}
