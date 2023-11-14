/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:58:21 by naal-jen          #+#    #+#             */
/*   Updated: 2023/11/11 18:50:11 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset(void)
{
	(*instructions()) = (t_instructions){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void	check_stack_a(t_list **stack_a)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp && *(int *)tmp->content != 0)
	{
		ft_rotate_a(stack_a, 0);
		tmp = *stack_a;
	}
}

void	pushing_b(t_list **stack_a, t_list **stack_b, int *arr, int seq)
{
	bool	flag;
	int		i;
	t_list	*tmp;

	flag = false;
	i = 0;
	tmp = *stack_a;
	// printf("seq: %d\n", seq);
	while ((ft_lstsize(*stack_a) - 1) != seq)
	{
		while (i <= seq)
		{
			// printf("arr[i]: %d\ntmp: %d\n", arr[i], *(int *)tmp->content);
			if (arr[i] == *(int *)tmp->content)
			{
				ft_rotate_a(stack_a, 0);
				tmp = *stack_a;
				i = 0;
				flag = true;
			}
			if (flag == true)
				break ;
			i++;
		}
		if (flag == true)
		{
			flag = false;
			continue ;
		}
		else
		{
			ft_push_b(stack_a, stack_b);
			tmp = *stack_a;
			i = 0;
		}
	}
	// print_list_a(stack_a);
	// print_list_b(stack_b);
}

int	*create_lis_arr(t_list **stack_a, t_list **stack_b, int value, int seq)
{
	t_list	*tmp;
	int		*arr;
	int		cur_val;
	int		i;

	i = 0;
	arr = (int *)ft_calloc(seq + 1, sizeof(int));
	if (!arr)
		return ((void *)0);
	tmp = *stack_a;
	while (tmp && *(int *)tmp->content != value)
		tmp = tmp->next;
	arr[i] = *(int *)tmp->content;
	i++;
	cur_val = *(int *)tmp->content;
	while (tmp)
	{
		if (cur_val < *(int *)tmp->content)
		{
			arr[i] = *(int *)tmp->content;
			cur_val = *(int *)tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	// i = 0;
	// printf("i: %d, seq: %d\n", i, seq);
	// while (i <=seq)
	// {
	// 	printf("hi: %d\n", arr[i]);
	// 	i++;
	// }
	pushing_b(stack_a, stack_b, arr, seq);
	//! This should be placed in a loop while (ft_lstsize(stack_b) != 0);
	while (ft_lstsize(*stack_b) != 0)
	{
		print_list_a(stack_a);
		print_list_b(stack_b);
		instructions()->mov_a = check_stack_a_moves(*stack_a, *stack_b);
		if (ft_lstsize(*stack_b) != 1) //! if not will get a segfault when having only one element;
			instructions()->mov_b = check_stack_b_moves(*stack_a, *stack_b);
		instructions()->mov_bb = check_both_moves(*stack_a, *stack_b);
		printf("\nmove_a: %d\n", instructions()->mov_a);
		printf("\nmove_b: %d\n", instructions()->mov_b);
		printf("\nmove_both: %d\n", instructions()->mov_bb);
		printf("modes:\nma_to_top:%d\nma_to_bottom:%d\nmb_to_top:%d\nmb_to_bottom:%d\nm_a:%d\nm_b:%d\nm_bb:%d\n", instructions()->ma_to_top, instructions()->ma_to_bottom, instructions()->mb_to_top, instructions()->mb_to_bottom, instructions()->m_a, instructions()->m_b, instructions()->m_bb);
		if (instructions()->mov_bb == 0)
		{
			if (instructions()->mov_a < instructions()->mov_b || instructions()->mov_b == 0)
				ex_mov_a(stack_a, stack_b);
			else
				ex_mov_b(stack_a, stack_b);
		}
		else if (instructions()->mov_b == 0)
		{
			if (instructions()->mov_a < instructions()->mov_bb || instructions()->mov_bb == 0)
				ex_mov_a(stack_a, stack_b);
			else
				ex_mov_bb(stack_a, stack_b);
		}
		else
		{
			if (instructions()->mov_a < instructions()->mov_b && instructions()->mov_a < instructions()->mov_bb)
				ex_mov_a(stack_a, stack_b);
			else if (instructions()->mov_b < instructions()->mov_a && instructions()->mov_b < instructions()->mov_bb)
				ex_mov_b(stack_a, stack_b);
			else
				ex_mov_bb(stack_a, stack_b);
		}
		reset();
	}
	check_stack_a(stack_a);
	print_list_a(stack_a);
	print_list_b(stack_b);
	return (arr);
}

void	cluster_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp_for_element;
	int		value; // The number holdeing the largest sequence.
	int		seq;
	int		seq_attuale;
	int		f_el; // first_element;
	int		list_size;
	int		current_value;

	(void)stack_b;
	tmp = *stack_a;
	tmp_for_element = *stack_a;
	list_size = ft_lstsize(*stack_a) + 1;
	seq_attuale = 0;
	seq = 0;
	while(--list_size)
	{
		f_el = *(int *)tmp_for_element->content;
		current_value = f_el;
		// printf("f_el: %d\n", f_el);
		tmp_for_element = tmp_for_element->next;
		tmp = tmp_for_element;
		while (tmp)
		{
			if (f_el < *(int *)tmp->content)
			{
				seq++;
				f_el = *(int *)tmp->content;
			}
			tmp = tmp->next;
		}
		if (seq > seq_attuale)
		{
			seq_attuale = seq;
			value = current_value;
		}
		seq = 0;
	}
	printf("seq: %d\n", seq_attuale);
	printf("value: %d\n", value);
	create_lis_arr(stack_a, stack_b, value, seq_attuale);
	// print_list(stack_a);
	// printf("me seq: %d\nme num: %d\n", seq_attuale, value);
}
