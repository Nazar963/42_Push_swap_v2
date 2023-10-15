/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:02:01 by naal-jen          #+#    #+#             */
/*   Updated: 2023/10/12 18:35:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hash(int key)
{
	return ((unsigned)key % HASH_TABLE_SIZE);
}

bool	ft_check_duplicates_two(int ac, char **av)
{
	bool		hash_table[HASH_TABLE_SIZE];
	int			i;
	long long	num;
	int			key;

	i = -1;
	while (++i < HASH_TABLE_SIZE)
		hash_table[i] = false;
	i = 0;
	while (++i < ac)
	{
		num = ft_atoi(av[i]);
		key = hash(num);
		if (hash_table[key])
			return (false);
		hash_table[key] = true;
	}
	return (true);
}

bool	ft_check_duplicates_one(char **av)
{
	bool		hash_table[HASH_TABLE_SIZE];
	char		**str;
	int			i;
	long long	num;
	int			key;

	i = -1;
	while (++i < HASH_TABLE_SIZE)
		hash_table[i] = false;
	str = ft_split(av[1], ' ');
	i = -1;
	while (str[++i])
	{
		num = ft_atoi(str[i]);
		key = hash(num);
		if (hash_table[key])
		{
			ft_free(str);
			return (false);
		}
		hash_table[key] = true;
	}
	ft_free(str);
	return (true);
}

int	ft_check_duplicates(int ac, char **av)
{
	int	res;

	res = 0;
	if (ac == 2)
		res = ft_check_duplicates_one(av);
	else
		res = ft_check_duplicates_two(ac, av);
	return (res);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_loco	*loco;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(EXIT_FAILURE);
	else if (ac == 2)
		ft_create_list(av, &stack_a);
	else if (ac > 2)
	{
		loco = (t_loco *)malloc(sizeof(t_loco));
		if (!loco)
			exit(EXIT_FAILURE);
		ft_create_lists(ac, av, &stack_a, loco);
	}
	main_helper(ac, av, &stack_a, loco);
	if (ft_lstsize(stack_a) <= 5)
		sort_5_numbers(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) > 5)
		cluster_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	if (ac > 2)
		free(loco);
}
