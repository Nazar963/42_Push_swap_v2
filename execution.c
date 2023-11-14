/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:28:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/11/11 18:00:29 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_mov_a(t_list **stack_a, t_list **stack_b)
{
	if (instructions()->ma_to_bottom == 1)
		while (--instructions()->mov_a)
			ft_reverse_rotate_a(stack_a, 0);
	else
		while (--instructions()->mov_a)
			ft_rotate_a(stack_a, 0);
	ft_push_a(stack_a, stack_b);
}

void	ex_mov_b(t_list **stack_a, t_list **stack_b)
{
	if (instructions()->mb_to_bottom == 1)
		while (--instructions()->mov_b)
			ft_reverse_rotate_b(stack_b, 0);
	else
		while (--instructions()->mov_b)
			ft_rotate_b(stack_b, 0);
	ft_push_a(stack_a, stack_b);
}

void	ex_mov_bb(t_list **stack_a, t_list **stack_b)
{
	while (--instructions()->mov_bb)
		ft_rr(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}

