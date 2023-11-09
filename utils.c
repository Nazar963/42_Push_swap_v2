/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:28:24 by naal-jen          #+#    #+#             */
/*   Updated: 2023/11/06 20:50:19 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_a(t_list **stack_a)
{
	t_list *tmp_a;
	int	i;

	i = 0;
	tmp_a = *stack_a;
	// min = *(int *)stack_a->content;
	printf("\n");
	while (tmp_a != NULL)
	{
		// if (*(int *)stack_a->content < min)
		// 	min = *(int *)stack_a->content;
		printf("stack_a[%d]: %d\n", i, *(int *)tmp_a->content);
		tmp_a = tmp_a->next;
		i++;
	}
	// return (min);
}

void	print_list_b(t_list **stack_b)
{
	t_list	*tmp_b;
	int	i;

	i = 0;
	tmp_b = *stack_b;
	// min = *(int *)stack_a->content;
	printf("\n");
	while (tmp_b != NULL)
	{
		// if (*(int *)stack_a->content < min)
		// 	min = *(int *)stack_a->content;
		printf("stack_b[%d]: %d\n", i, *(int *)(tmp_b)->content);
		tmp_b = (tmp_b)->next;
		i++;
	}
	// return (min);
}