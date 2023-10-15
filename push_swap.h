/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:55:13 by naal-jen          #+#    #+#             */
/*   Updated: 2023/10/12 18:00:30 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# define INT_MAX 2147483647
# define HASH_TABLE_SIZE 1000000

typedef struct s_loco
{
	long int	*value;
}	t_loco;

//--------------- main.c ------------------------------
int		ft_check_duplicates(int ac, char **av);

//--------------- main_helper.c -----------------------
void	main_helper(int ac, char **av, t_list **stack_a, t_loco *loco);

//--------------- create_list.c ----------------
void	ft_create_list(char **av, t_list **stack_a);
void	ft_create_lists(int ac, char **av, t_list **stack_a, t_loco *loco);
int		binary_search(int a[], int e, int l, int r);
void	quick_sort(int arr[], int left, int right);

//--------------- create_list_helper.c ---------
void	swap(int *arr, int i, int j);
int		*ft_copy_nums(int i, char **nums, int *arr, long int *new_num);
void	ft_add_to_list(t_list **stack_a, int size, long int *new_num, int *arr);
void	copy_nums(int i, char **av, int *arr, t_loco *loco);

//--------------- push.c --------------------
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);

//--------------- swap.c --------------------
void	ft_swap_a(t_list **stack_a, int print);
void	ft_swap_b(t_list **stack_b, int print);
void	ft_ss(t_list **stack_a, t_list **stack_b);

//--------------- rotate.c ------------------
void	ft_rotate_a(t_list **stack_a, int print);
void	ft_rotate_b(t_list **stack_b, int print);
void	ft_rr(t_list **stack_a, t_list **stack_b);

//--------------- reverse_rotate.c ----------
void	ft_reverse_rotate_a(t_list **stack_a, int print);
void	ft_reverse_rotate_b(t_list **stack_b, int print);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

//--------------- checks.c ---------------------
int		ft_check_if_num(int ac, char **av);
int		ft_check_if_sorted(int ac, char **av);

//--------------- sort_5.c -------------
void	sort_5_numbers(t_list **stack_a, t_list **stack_b);

//--------------- cluster_sort.c -----------------
void	cluster_sort(t_list **stack_a, t_list **stack_b);

//--------------- ft_free.c -------------------
void	ft_free(char **str);

/* --------------------------------- utils.c -------------------------------- */
void	print_list(t_list **stack_a);

#endif