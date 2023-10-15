/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:12:38 by naal-jen          #+#    #+#             */
/*   Updated: 2023/08/18 15:01:10 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack != NULL)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	get_index(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (*(int *)stack->content == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	sort_3_number_helper(t_list **stack_a)
{
	ft_reverse_rotate_a(stack_a, 0);
	ft_swap_a(stack_a, 0);
}

void	sort_3_numbers(t_list **stack_a)
{
	int	tmp;
	int	tmp_n;

	tmp = *(int *)(*stack_a)->content;
	tmp_n = *(int *)(*stack_a)->next->content;
	if (!(*stack_a)->next->next && tmp > tmp_n)
		ft_swap_a(stack_a, 0);
	else if (tmp > tmp_n
		&& tmp < *(int *)(*stack_a)->next->next->content)
		ft_swap_a(stack_a, 0);
	else if (tmp > *(int *)(*stack_a)->next->next->content
		&& tmp_n < *(int *)(*stack_a)->next->next->content)
		ft_rotate_a(stack_a, 0);
	else if (tmp < tmp_n
		&& tmp_n > *(int *)(*stack_a)->next->next->content &&
		tmp < *(int *)(*stack_a)->next->next->content)
		sort_3_number_helper(stack_a);
	else if (tmp < tmp_n
		&& tmp_n > *(int *)(*stack_a)->next->next->content &&
		tmp > *(int *)(*stack_a)->next->next->content)
		ft_reverse_rotate_a(stack_a, 0);
	else if (tmp > tmp_n
		&& tmp_n > *(int *)(*stack_a)->next->next->content)
	{
		ft_swap_a(stack_a, 0);
		ft_reverse_rotate_a(stack_a, 0);
	}
}

void	sort_5_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	i;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		i = get_index(*stack_a, min);
		if (i < 3)
		{
			while (*(int *)(*stack_a)->content != min)
				ft_rotate_a(stack_a, 0);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min)
				ft_reverse_rotate_a(stack_a, 0);
		}
		ft_push_b(stack_a, stack_b);
	}
	sort_3_numbers(stack_a);
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
}
