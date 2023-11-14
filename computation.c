/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:07:17 by naal-jen          #+#    #+#             */
/*   Updated: 2023/11/11 19:04:22 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//! include count in the calculation.

int	check_stack_b_moves(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		target;

	target = 0;
	if (*(int *)stack_a->content == 0)
	{
		// if (*(int *)stack_a->next->content - 1 == *(int *)stack_a->content)
		return (0);
		//* if the stack_a->next->content - 1 == stack_a->content exit;
		// count++;
		// tmp_a = stack_a->next;
		// tmp_b = stack_b;
	}
	else
	{
		tmp_a = stack_a;
		tmp_b = stack_b;
	}

	//* Here i will loop the stack_b in order to find and store the index of - 1 elemnt of the first element in stack_a
	while (tmp_b)
	{
		target++;
		if (*(int *)tmp_b->content == (*(int *)tmp_a->content - 1))
			break ;
		tmp_b = tmp_b->next;
	}
	if (target <= (ft_lstsize(stack_b) / 2))
	{
		instructions()->m_b = 1;
		instructions()->mb_to_top = 1;
		return (target);
	}
	instructions()->m_b = 1;
	instructions()->mb_to_bottom = 1;
	return (target = ft_lstsize(stack_b) - target + 2);
}

int	check_stack_a_moves(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int			target;

	tmp_a = stack_a;
	tmp_b = stack_b;
	target = 0;
	//* Here i will loop the stack_b in order to find and store the index of - 1 elemnt of the first element in stack_a
	while (tmp_a)
	{
		target++;
		if (*(int *)tmp_a->content == (*(int *)tmp_b->content + 1))
			break ;
		tmp_a = tmp_a->next;
	}
	if (target <= (ft_lstsize(stack_a) / 2))
	{
		instructions()->m_a = 1;
		instructions()->ma_to_top = 1;
		return (target);
	}
	instructions()->m_a = 1;
	instructions()->ma_to_bottom = 1;
	return (ft_lstsize(stack_a) - target + 2);
}

//! check for if its working
int	check_both_moves(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		target;

	target = 0;
	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a && tmp_b)
	{
		target++;
		if (*(int *)tmp_a->content == (*(int *)tmp_b->content - 1))
		{
			instructions()->m_bb = 1;
			break ;
		}
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	if (ft_lstsize(stack_a) > ft_lstsize(stack_b) && instructions()->m_bb == 1)
	{
		if (target <= (ft_lstsize(stack_a) / 2))
			return (target);
	}
	else if (ft_lstsize(stack_a) == ft_lstsize(stack_b) && instructions()->m_bb == 1)
	{
		if (target <= (ft_lstsize(stack_a) / 2))
			return (target);
		return (ft_lstsize(stack_a) - target + 2);
	}
	return (0);
}