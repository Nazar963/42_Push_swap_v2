/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:28:24 by naal-jen          #+#    #+#             */
/*   Updated: 2023/10/13 17:17:27 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **stack_a)
{
	// int	min;
	int	i;

	i = 0;

	// min = *(int *)stack_a->content;
	while (*stack_a != NULL)
	{
		// if (*(int *)stack_a->content < min)
		// 	min = *(int *)stack_a->content;
		printf("stack_a[%d]: %d\n", i, *(int *)(*stack_a)->content);
		*stack_a = (*stack_a)->next;
		i++;
	}
	// return (min);
}
// void	print_list_b(t_list **stack_a)
// {
// 	// int	min;
// 	int	i;

// 	i = 0;

// 	// min = *(int *)stack_a->content;
// 	while (*stack_a != NULL)
// 	{
// 		// if (*(int *)stack_a->content < min)
// 		// 	min = *(int *)stack_a->content;
// 		printf("stack_a[%d]: %d\n", i, *(int *)(*stack_a)->content);
// 		*stack_a = (*stack_a)->next;
// 		i++;
// 	}
// 	// return (min);
// }