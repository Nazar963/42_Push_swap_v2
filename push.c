/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:47:38 by naal-jen          #+#    #+#             */
/*   Updated: 2023/03/03 18:00:23 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b || !(*stack_b))
		return ;
	temp = *stack_b;
	if (!*stack_a)
		ft_lstadd_back(stack_a, ft_lstnew((int *)(*stack_b)->content));
	else
		ft_lstadd_front(stack_a, ft_lstnew((int *)(*stack_b)->content));
	*stack_b = (*stack_b)->next;
	free(temp);
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;

	if (!stack_a || !(*stack_a))
		return ;
	temp_a = *stack_a;
	if (!*stack_b)
		ft_lstadd_back(stack_b, ft_lstnew((int *)(*stack_a)->content));
	else
		ft_lstadd_front(stack_b, ft_lstnew((int *)(*stack_a)->content));
	*stack_a = (*stack_a)->next;
	free(temp_a);
	ft_putstr_fd("pb\n", 1);
}
